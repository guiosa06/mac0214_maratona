#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2*1e5+5;
const int INF = 1e9;

vector<int> adj[MAXN];
int dp0[MAXN]; // subtree root is not included in matching
int dp1[MAXN]; // subtree root is included in matching

void dfs(int at, int pai=-1) {
    int chosenSon=0, minDif=INF;
    for(auto to:adj[at]) {
        if(to!=pai) {
            dfs(to, at);
            if(dp1[to]-dp0[to]<minDif) { chosenSon = to; minDif = dp1[to]-dp0[to]; }
            dp0[at] += max(dp0[to], dp1[to]);
        }
    }

    if(chosenSon>0) dp1[at] = dp0[at] - max(dp0[chosenSon], dp1[chosenSon]) + dp0[chosenSon] + 1;
}

int main() {
    int n; cin >> n;
    for(int i=0; i<n-1; i++) { 

        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);
    cout << max(dp0[1], dp1[1]) << "\n";
    // for(int i=1; i<=n; i++) cout << dp0[i] << " " << dp1[i] << "\n";

    return 0;
}