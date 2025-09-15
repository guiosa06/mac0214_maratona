#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int MAXN=1e5+5;

vector<int> adj[MAXN];
int vis[MAXN];

int timer=0, low[MAXN], id[MAXN];
stack<int> s;
int c=0, comp[MAXN], comp_id[MAXN];
void dfs(int at) {
    low[at]=id[at]=++timer;
    vis[at]=1;
    s.push(at);
    
    for(auto to:adj[at]) {
        if(!vis[to]) {
            dfs(to);
            low[at] = min(low[at], low[to]);
        }
        else if(vis[to]==1) low[at] = min(low[at], id[to]);
    }

    if(low[at]==id[at]) {
        c++;
        comp_id[c]=at;
        while(true) {
            int v=s.top(); s.pop();
            comp[v]=c; vis[v]=2;
            if(v==at) break;
        }
    }
}


int vis2[MAXN];
vector<int> adj2[MAXN];
int indeg[MAXN], outdeg[MAXN];
void compress(int at) {
    vis2[at]=1;
    for(auto to:adj[at]) {
        if(!vis2[to]) {
            compress(to);
        } 
        if(comp[at]!=comp[to]){
            adj2[comp[at]].push_back(comp[to]);
            indeg[comp[to]]++;
            outdeg[comp[at]]++;
        }
    }
}


int S[MAXN], T[MAXN];
int pares_feitos=0;
int vis3[MAXN];
bool achaMeuPar(int at, int source) {
    vis3[at]=1;
    if(outdeg[at]==0) {
        S[pares_feitos] = source;
        T[pares_feitos] = at;
        pares_feitos++;
        return 1;
    }
    for(auto to:adj2[at]) {
        if(!vis3[to] && achaMeuPar(to, source)) return 1;
    }

    return 0;
}


int main() {
    int n,m; cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
    }

    for(int i=1; i<=n; i++)
        if(!vis[i]) dfs(i);

    if(c==1) {
        cout << 0 << "\n";
        return 0;
    }

    for(int i=1; i<=n; i++)
        if(!vis2[i]) compress(i);

    for(int i=1; i<=c; i++)
        if(indeg[i]==0) achaMeuPar(i,i); 

    vector<pii> novas_arestas;
    for(int i=0; i<pares_feitos; i++) {
        int ni = (i+1)%pares_feitos;
        outdeg[T[i]]++; indeg[S[ni]]++;

        novas_arestas.push_back({comp_id[T[i]], comp_id[S[ni]]});
    }

    queue<int> s_left, t_left;
    for(int i=1; i<=c; i++) {
        if(indeg[i]==0) s_left.push(i);
        else if(outdeg[i]==0) t_left.push(i);
    }

    while(s_left.size()<t_left.size()) s_left.push(S[0]);
    while(s_left.size()>t_left.size()) t_left.push(T[0]);

    while(!s_left.empty()) {
        pares_feitos++;
        novas_arestas.push_back({comp_id[t_left.front()], comp_id[s_left.front()]});
        t_left.pop(); s_left.pop();
    }

    cout << pares_feitos << "\n";
    for(auto p:novas_arestas) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}