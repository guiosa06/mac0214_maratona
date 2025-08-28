#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 50005;

vector<int> adj[MAXN];
ll dp[MAXN][501];   // dp[i][j] = total de caminhos com tamanho j terminando em i na subtree de i
int k;
ll resp=0;

void dfs(int at, int pai=-1) {

    dp[at][0]=1;

    for(auto to:adj[at]) {
        if(to!=pai) {
            dfs(to, at);

            // conta caminhos de tamanho k na subtree de at, passando por at
            // para isso, faz combinação de caminho com filho atual to e caminhos de filhos anteriores
            ll kpaths = 0;
            for(int i=1; i<=k; i++) kpaths += (dp[to][i-1]*dp[at][k-i]);
            resp += kpaths;

            // atualiza caminhos de i
            for(int i=1; i<=k; i++) dp[at][i] += dp[to][i-1];
        }
    }


}

int main() {
    int n; cin >> n >> k;
    for(int i=0; i<n-1; i++) {
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);
    cout << resp << "\n";
    return 0;
}