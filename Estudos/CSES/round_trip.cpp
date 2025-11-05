#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;

vector<int> adj[MAXN+1];
int pai[MAXN+1], vis[MAXN+1];

vector<int> cycle;
bool flag=0;

void dfs(int at) {
    vis[at]=1;
    for(int to:adj[at]) {
        if(flag) return;
        if(!vis[to]) {
            pai[to]=at;
            dfs(to);
        }
        else if(to!=pai[at]){
            flag=1;

            cycle.push_back(to);
            while(at!=to) { 
                cycle.push_back(at);
                at = pai[at];
            }
            cycle.push_back(at);

            cout << cycle.size() << "\n";
            for(int x:cycle) {
                cout << x << " ";
            }

            return;
        }
    }
}

int main() {
    int n, m; cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1; i<=n; i++) {
        if(!vis[i]) dfs(i);
        if(flag) break;
    }
    if(!flag) cout << "IMPOSSIBLE\n";

    return 0;
}