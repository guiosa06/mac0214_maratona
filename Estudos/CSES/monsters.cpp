#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e3+5;
const int INF=1e9;
typedef pair<int,int> pii;

int ni[4]={0,0,-1,1};
int nj[4]={-1,1,0,0};
char dir[4]={'L','R','U','D'};

char g[MAXN][MAXN];
int dist1[MAXN][MAXN];
int dist2[MAXN][MAXN];
bool vis1[MAXN][MAXN];
bool vis2[MAXN][MAXN];
int ant[MAXN][MAXN];

int main() {

    for(int i=0; i<MAXN; i++) for(int j=0; j<MAXN; j++) { dist1[i][j]=INF; dist2[i][j]=INF; }

    int n,m; cin >> n >> m;
    pii s;
    queue<pii> q;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> g[i][j];
            if(g[i][j]=='A') {
                s={i,j};
                dist2[i][j]=0;
            }
            else if(g[i][j]=='M') {
                q.push({i,j});
                dist1[i][j]=0;
            }
        }
    }

    while(!q.empty()) {
        int i=q.front().first, j=q.front().second;
        q.pop();

        if(vis1[i][j]) continue;
        vis1[i][j]=1;

        for(int k=0; k<4; k++) {
            int I = i+ni[k], J = j+nj[k];
            if((g[I][J]=='.' || g[I][J]=='A') && !vis1[I][J]) {
                dist1[I][J] = min(dist1[I][J], dist1[i][j]+1);
                q.push({I,J});
            }
        }
    }

    q.push(s);
    while(!q.empty()) {
        int i=q.front().first, j=q.front().second;
        q.pop();

        if(i==1 || i==n || j==1 || j==m) {
            stack<char> p;
            while(i!=s.first || j!=s.second) {
                p.push(dir[ant[i][j]]);
                int I = i-ni[ant[i][j]], J = j-nj[ant[i][j]];
                i=I, j=J;
            }
            cout << "YES\n";
            cout << p.size() << "\n";
            while(!p.empty()) {
                cout << p.top();
                p.pop();
            }
            cout << "\n";
            return 0;
        }

        if(vis2[i][j]) continue;
        vis2[i][j]=1;

        for(int k=0; k<4; k++) {
            int I = i+ni[k], J = j+nj[k];
            if((g[I][J]=='.') && !vis2[I][J]) {
                if(dist2[I][J] > dist2[i][j]+1) {
                    dist2[I][J] = dist2[i][j]+1;
                    if(dist1[I][J]>dist2[I][J]) {
                        q.push({I,J});
                        ant[I][J]=k;
                    }
                }
            }
        }
    }

    cout << "NO\n";


    return 0;
}