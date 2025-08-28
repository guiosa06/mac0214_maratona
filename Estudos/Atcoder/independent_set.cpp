#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+5;
const int MOD = 1e9+7;

auto add = [](int a, int b) {
    return (a+b)%MOD;
};
auto mul = [](int a, int b) {
    return (a*(long long)b)%MOD;
};

vector<int> adj[MAXN];
int dp0[MAXN];  // subtree root white
int dp1[MAXN];  // subtree root black

void dfs(int at, int pai=-1) {
    dp0[at] = dp1[at] = 1;
    for(auto to:adj[at]) {
        if(to!=pai) {
            dfs(to, at);
            dp0[at] = mul(dp0[at],add(dp0[to],dp1[to]));
            dp1[at] = mul(dp1[at], dp0[to]);
        }
    }
}

int main() {
    int n; cin >> n;
    for(int i=0; i<n-1; i++) { 
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);
    cout << add(dp0[1], dp1[1]) << "\n";

    return 0;
}