#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2500;
const ll INF=1e15;

struct Edge {
    int a,b;
    ll c;
};
vector<Edge> E, adj[MAXN+1];
ll d[MAXN+1];
int pred[MAXN+1];

bool flag=0;

void bellmanford(int n) {
    for(int i=1; i<=n; i++) d[i]=0; // pontos de partida simultâneos

    for(int j=0; j<n-1; j++) 
        for(auto e:E) 
            if(d[e.a]!=INF && d[e.b]>d[e.a]+e.c) {
                pred[e.b] = e.a;
                d[e.b] = d[e.a]+e.c;
            }
    
    int last_relaxed=0;
    for(auto e:E) 
        if(d[e.a]!=INF && d[e.b]>d[e.a]+e.c) {
            pred[e.b] = e.a;
            last_relaxed = e.b;
        }

    if(last_relaxed>0) {
        for(int j=0; j<n; j++) last_relaxed=pred[last_relaxed];

        int at=last_relaxed;
        stack<int> s;
        s.push(at);
        at = pred[at];

        while(at!=last_relaxed) {
            s.push(at);
            at = pred[at];
        }
        s.push(at);

        cout << "YES\n";
        while(!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << "\n";
        flag=1;
        return;
    }
            

}

int main() {
    int n,m; cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a,b,c; cin >> a >> b >> c;
        E.push_back({a,b,c});
        adj[a].push_back({a,b,c});
    }

    bellmanford(n);
    if(!flag) cout << "NO\n";
    return 0;
}