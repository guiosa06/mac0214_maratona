#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
const int MAXM = 2*1e5;

struct Edge {
    int to;
    int idx;
};

bool vis[MAXM];
int deg[MAXN+1];
vector<Edge> adj[MAXN+1];
vector<int> path;

void dfs(int at) {
    while(!adj[at].empty()) {
        Edge e = adj[at].back();
        adj[at].pop_back();
        if(!vis[e.idx]) {
            vis[e.idx]=1;
            dfs(e.to);
        }
    }
    path.push_back(at);
}

int main() {
    int n, m; cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a,b; cin >> a >> b;
        adj[a].push_back({b,i});
        adj[b].push_back({a,i});
        deg[a]++; deg[b]++;
    }

    for(int i=1; i<=n; i++) 
        if(deg[i]%2) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }

    dfs(1);
    if(path.size()!=m+1) {
        cout << "IMPOSSIBLE\n"; 
        return 0;
    }
    for(int i=0; i<path.size(); i++) cout << path[i] << " ";
    cout << "\n";


    return 0;
}