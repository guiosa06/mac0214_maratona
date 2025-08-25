#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+5;
const int INF = 1e9;

int p[MAXN], v[MAXN], resp[MAXN];
vector<int> adj[MAXN], aux;

int n;

void dfs(int at, int pai=n+1) {

    // CALCULAR RESPOSTA
    auto it=lower_bound(aux.begin(), aux.end(), v[at]);
    int pos = it-aux.begin();
    int prev = aux[pos];

    resp[at] = max(pos, resp[pai]);

    // ADICIONAR AT
    aux[pos]=v[at];

    for(int to:adj[at]) {
        if(to!=pai) dfs(to, at);
    }

    // RETIRAR AT
    aux[pos]=prev;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for(int i=2; i<=n; i++) {
        int pai; cin >> pai;
        adj[pai].push_back(i);
        adj[i].push_back(pai);
    }

    for(int i=1; i<=n; i++) {
        cin >> v[i];
    }

    aux.push_back(-INF);
    for(int i=1; i<=n+1; i++) {
        aux.push_back(INF);
    }

    dfs(1);

    for(int i=2; i<=n; i++) cout << resp[i] << " ";
    cout << "\n";

}