#include <bits/stdc++.h>
using namespace std;
const int MAXN =  2*1e5;

int c[MAXN+1], resp[MAXN+1];
vector<int> adj[MAXN+1];
set<int> s[MAXN+1];

void dfs(int at, int pai=0) {
    s[at].insert(c[at]);
    for(auto to:adj[at]) {
        if(to==pai) continue;
        dfs(to, at);
        if(s[to].size()>s[at].size()) swap(s[to], s[at]);
        for(auto color:s[to]) s[at].insert(color);
    }

    resp[at] = s[at].size();
}

int main() {
    int n; cin >> n;
    for(int i=1; i<=n; i++) cin >> c[i];
    for(int i=0; i<n-1; i++) {
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1);
    for(int i=1; i<=n; i++) cout << resp[i] << " ";
    cout << "\n";
    return 0;
}