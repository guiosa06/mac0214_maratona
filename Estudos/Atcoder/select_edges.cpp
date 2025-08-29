#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pii;
const int MAXN=3*1e5+5;

vector<pii> adj[MAXN];
int d[MAXN];
ll dp0[MAXN];   // máximo peso com no máximo d[i] arestas 
ll dp1[MAXN];   // máximo peso com no máximo d[i]-1 arestas
vector<ll> aux[MAXN];

void dfs(int at, int pai=-1) {
    for(auto p:adj[at]) {
        int to = p.first; ll w = p.second;
        if(to==pai) continue;
        dfs(to, at);
        
        dp0[at]+=dp0[to];
        dp1[at]+=dp0[to];
        if(dp0[to]<dp1[to]+w && d[to]>0LL) aux[at].push_back(dp1[to]-dp0[to]+w);
    }

    sort(aux[at].begin(), aux[at].end());
    reverse(aux[at].begin(), aux[at].end());
    for(int i=0; i<aux[at].size(); i++) {
        if(i<d[at]) dp0[at]+=aux[at][i];
        if(i<d[at]-1) dp1[at]+=aux[at][i];
    }
}

int main() {
    int n; cin >> n;
    for(int i=1; i<=n; i++) cin >> d[i];
    for(int i=0; i<n-1; i++) {
        int a,b; ll w;
        cin >> a >> b >> w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }

    dfs(1);
    cout << dp0[1] << "\n";
    // for(int i=1; i<=n; i++) cout << dp0[i] << " " << dp1[i] << "\n";
    return 0;
}