#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5;

int c[MAXN+1], resp[MAXN];
vector<int> adj[MAXN+1];
map<int, int> freq[MAXN+1];
map<int, int> atLeast[MAXN+1]; 
// atleast[v][f] = total de cores na subárvore de v 
// com frequência maior ou igual a f

struct Query {
    int k, i;
};
vector<Query> queries[MAXN+1];

void dfs(int at, int pai=0) {

    freq[at][c[at]]=1;
    atLeast[at][1]=1;

    for(int to:adj[at]) {

        if(pai==to) continue;
        dfs(to, at);

        if(freq[to].size() > freq[at].size()) {
            swap(freq[to], freq[at]);
            swap(atLeast[to], atLeast[at]);
        }
        for(auto p:freq[to]) {
            for(int i=0; i<p.second; i++) {
                freq[at][p.first]++;
                atLeast[at][freq[at][p.first]]++;
            }
        }
    }

    for(auto q:queries[at]) {
        resp[q.i] = atLeast[at][q.k];
    }
}

int main() {
    int n,m; cin >> n >> m;
    for(int i=1; i<=n; i++)
        cin >> c[i];

    for(int i=0; i<n-1; i++) {
        int x,y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=0; i<m; i++) {
        int v, k; cin >> v >> k;
        queries[v].push_back({k,i});
    }

    dfs(1);
    for(int i=0; i<m; i++) cout << resp[i] << "\n";
}