#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5;

int c[MAXN+1], maxF[MAXN+1];
ll sum[MAXN+1];
vector<int> adj[MAXN+1];
map<int, int> freq[MAXN+1];

void dfs(int at, int pai=0) {

    sum[at]= ll(c[at]), maxF[at]=1;
    freq[at][c[at]]=1;

    for(int to:adj[at]) {

        if(pai==to) continue;
        dfs(to, at);

        if(freq[to].size() > freq[at].size()) {
            swap(freq[to], freq[at]);
            sum[at] = sum[to]; maxF[at] = maxF[to];
        }
        for(auto p:freq[to]) {
            freq[at][p.first] += p.second;

            if(freq[at][p.first] > maxF[at]) {
                maxF[at] = freq[at][p.first];
                sum[at] = ll(p.first);
            }
            else if(freq[at][p.first] == maxF[at]) sum[at] += ll(p.first);
        }
    }
}

int main() {
    int n; cin >> n;
    for(int i=1; i<=n; i++)
        cin >> c[i];

    for(int i=0; i<n-1; i++) {
        int x,y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1);
    for(int i=1; i<=n; i++) cout << sum[i] << " ";
    cout << "\n";
}