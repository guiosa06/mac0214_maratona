#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2*1e5+5;
const int INF=1e9;
const int LOGM = 30;

int t[MAXN];
int depth[MAXN];
vector<int> depthV[MAXN];
ll depthSum[MAXN];
ll maxSum=0LL;
int maxDepth=0;

vector<int> adj[MAXN];

int n, p;
int pai[LOGM][MAXN];
int in[MAXN], out[MAXN];
void dfs0(int k) {
    in[k] = p++;
    for(int i=0; i<(int)adj[k].size(); i++)
        if(in[adj[k][i]]==-1) {
            pai[0][adj[k][i]] = k;
            dfs0(adj[k][i]);
        }
    out[k]=p++;
}

void build(int raiz) {
    for(int i=0; i<n; i++) pai[0][i] = i;
    p=0, memset(in,-1,sizeof in);
    dfs0(raiz);

    for(int k=1; k<LOGM; k++) for(int i=0; i<n; i++)
        pai[k][i] = pai[k-1][pai[k-1][i]];
}

bool anc(int a, int b) {
    return in[a] <= in[b] and out[a] >= out[b];
}

int lca(int a, int b) {
    if(anc(a,b)) return a;
    if(anc(b,a)) return b;

    for(int k=LOGM-1; k>=0; k--)
        if(!anc(pai[k][a], b)) a = pai[k][a];
    
        return pai[0][a];
}


void dfs(int at, int pai=1, int h=1) {

    depth[at]=h;
    if(t[at]!=0) depthV[h].push_back(at);
    depthSum[h] += 1LL*t[at];
    maxSum = max(maxSum, depthSum[h]);

    for(auto to:adj[at]) {
        if(to!=pai) {
            dfs(to, at, h+1);
        }
    }
}

void dfsLimpa(int at, int pai=1, int h=1) {

    if(t[at]!=0) depthV[h].pop_back();
    depthSum[h] = 0;

    for(auto to:adj[at]) {
        if(to!=pai) {
            dfsLimpa(to, at, h+1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=2; i<=n; i++) {
        cin >> t[i];
    }
    for(int i=0; i<n-1; i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    build(1);

    int resp=INF;
    ll maxSumAnterior=0;
    for(auto root:adj[1]) {

        dfs(root);
        if(maxSum==0) continue;
        if(maxSum>maxSumAnterior) resp=INF;

        vector<int> candidatos;

        for(int i=1; i<n; i++) {
            if(maxSum == depthSum[i]) candidatos.push_back(i);
        }

        for(auto d:candidatos) {
            int ancestor = depthV[d][0];
            for(int i=1; i<depthV[d].size(); i++) {
                ancestor = lca(ancestor, depthV[d][i]);
            }

            resp = min(resp, d - depth[ancestor]+1);
        }

        dfsLimpa(root);
        maxSumAnterior = maxSum;
    }

    cout << maxSum << " " << resp << "\n";

    return 0;
}