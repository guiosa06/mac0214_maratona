#include <bits/stdc++.h>
using namespace std;
const int MAX = 2*1e5;

struct Edge {
    int to, idx;
};

vector<Edge> adj[MAX];
bool vis[MAX];
int indeg[MAX], outdeg[MAX];
vector<int> path;

void dfs(int at) {
    while(!adj[at].empty()) {
        auto e = adj[at].back();
        adj[at].pop_back();
        if(vis[e.idx]) continue;
        vis[e.idx]=1;
        dfs(e.to);
    }
    path.push_back(at);
}

int main() {
    int n,m; cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a,b; cin >> a >> b;
        adj[a].push_back({b, i});
        indeg[b]++;
        outdeg[a]++;
    }

    if((outdeg[1]-indeg[1]!=1) || (indeg[n]-outdeg[n]!=1)) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for(int i=2; i<n; i++) {
        if(indeg[i]!=outdeg[i]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    dfs(1);
    if(path.size() != m+1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    reverse(path.begin(), path.end());
    for(int v:path) cout << v << " ";
    cout << "\n";
}