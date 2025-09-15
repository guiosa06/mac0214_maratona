#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5+5;

/// TARJAN
vector<int> adj[MAXN];
ll k[MAXN];
int vis[MAXN], id[MAXN], low[MAXN];
int timer=0;

stack<int> s;
int comp[MAXN], comp_at=0;
ll comp_sum[MAXN];

void dfs(int at) {
    id[at]=low[at]=++timer;
    s.push(at);
    vis[at]=1;     

    for(int to:adj[at]) {
        if(vis[to]==0) {
            dfs(to);
            low[at]=min(low[at],low[to]);
        }
        else if(vis[to]==1) {
            low[at]=min(low[at],id[to]);
        }
    }

    if(low[at] == id[at]) {
        comp_at++;
        while(true) {
            int v=s.top(); s.pop();
            vis[v]=2;
            comp[v]=comp_at;
            comp_sum[comp_at]+=k[v];
            if(v==at) break;
        }
    }
}

/// COMPRIMINDO SCCs
int vis2[MAXN];
vector<int> adj2[MAXN];
int indeg[MAXN];

void compress(int at) {
    vis2[at]=1;
    for(auto to:adj[at]) {
        if(!vis2[to]) {
            compress(to);
        } 
        if(comp[at]!=comp[to]){
            adj2[comp[at]].push_back(comp[to]);
            indeg[comp[to]]++;
        }
    }
}

/// ORD. TOPOLÓGICA E DP
ll dp[MAXN];
ll caminho_maximo() {
    ll resp = 0;
    queue<int> q;

    for(int i=1; i<=comp_at; i++) {
        if(indeg[i]==0) {
            q.push(i);
            dp[i] = comp_sum[i];
        }
    }

    while(!q.empty()) {
        int at=q.front(); q.pop();
        resp = max(resp, dp[at]);

        for(int to:adj2[at]) {
            dp[to] = max(dp[to], dp[at]+comp_sum[to]);
            indeg[to]--;
            if(indeg[to]==0) q.push(to);
        }
    }

    return resp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> k[i];
    for(int i=0; i<m; i++) {
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
    }

    for(int i=1; i<=n; i++) {
        if(vis[i]==0) {
            dfs(i);
        }
    }

    for(int i=1; i<=n; i++) {
        if(vis2[i]==0) {
            compress(i);
        }
    }
    
    cout << caminho_maximo() << "\n";

    return 0;
}