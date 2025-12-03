#include <bits/stdc++.h>
using namespace std;
const int MAXM = (1<<15);
 
struct Edge {
    int to;
    int idx; 
    int value;
};
 
vector<Edge> adj[MAXM];
vector<int> path;
bool vis[MAXM];
 
void dfs(int at) {
    while(!adj[at].empty()) {
        Edge e = adj[at].back();
        adj[at].pop_back();
 
        if(vis[e.idx]) continue;
        vis[e.idx]=1;
        dfs(e.to);
    }
    path.push_back(at);
}
 
int main() {
    int n; cin >> n;
    int idx=0;
    map<pair<int,int>,int> m;
 
    for(int i=0; i<(1<<(n-1)); i++) {
        // int a = (i&(1<<(n-2))); cout << a << " " ;
        int to0 = (i&(1<<(n-2)) ? (i-(1<<(n-2)))*2 : i*2);
        int to1 = to0 + 1;
        // cout << i << ": " << to0 << " " << to1 << "\n";
        adj[i].push_back({to0, idx++, 0});
        adj[i].push_back({to1, idx++, 1});
        m[{i, to0}]=0;
        m[{i,to1}]=1;
    }
 
    for(int i=0; i<n-1; i++) cout << 0;
    dfs(0);
    reverse(path.begin(), path.end());
    for(int i=0; i<path.size()-1; i++) {
        // cout << path[i] << " ";
        cout << m[{path[i], path[i+1]}];
    }
    cout << "\n";
}