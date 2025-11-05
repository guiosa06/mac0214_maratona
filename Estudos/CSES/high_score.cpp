#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2500;
const ll INF=1e15;


struct Edge {
    int a,b;
    ll x;
};
vector<Edge> E;
ll d[MAXN+1];
bool neg_cycle[MAXN+1];


vector<int> rev_adj[MAXN+1];
bool vis[MAXN+1];
bool dfs(int at) {
    vis[at]=1;
    if(neg_cycle[at]) return 1;
    bool aux=0;
    for(int to:rev_adj[at]) {
        if(!vis[to]) {
            aux = aux | dfs(to);
        }
    }
    return aux;
}

void BellmanFord(int n) {
    d[1]=0;
    for(int i=2; i<=n; i++) d[i]=INF;
    for(int t=0; t<n-1; t++) {
        for(auto e:E) {
            if(d[e.a]!=INF) d[e.b] = min(d[e.b], d[e.a]+e.x);
        }
    }

    for(auto e:E)
        if(d[e.a]!=INF && d[e.b]>d[e.a]+e.x) neg_cycle[e.b]=1;

    // for(int i=1; i<=n; i++) cout << d[i] << " " << neg_cycle[i] << "\n";

    if(dfs(n)) cout << -1 << "\n";
    else cout << -d[n] << "\n";
}

int main() {
    int n,m; cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a,b; ll x; 
        cin >> a >> b >> x;
        E.push_back({a,b,-x});
        rev_adj[b].push_back(a);
    }

    BellmanFord(n);
    
    return 0;
}