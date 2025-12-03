#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5;
    
vector<int> adj[MAXN+1];
int deg[MAXN+1];
bool vis[MAXN+1];
    
int tb;
vector<int> bh;
int v[3];
    
void dfs(int at, int start, int tot) {
    // cout << at << " ";
    vis[at]=1;
    if(deg[at]==3) {
        v[1]+=tot;
        // cout << "\n" << 1 << " "<< v[1];
        return;
    }
    
    for(auto to:adj[at]) {
        if(to==tb && at!=start) {
            v[0]+=(tot+1);
            // cout << "\n" << 0 << " "<< v[0];
            return;
        }
        if(!vis[to]) dfs(to,start,tot+1);
    }
}
    
void dfs1(int at, int tot) {
    vis[at]=1;
    
    for(auto to:adj[at]) {
        if(to==bh[1] && at!=bh[0]) {
            v[2]+=(tot+1);
            return;
        }
        if(!vis[to]) dfs1(to,tot+1);
    }
}
    
int main(){
    int n; cin >> n;
    for(int i=0; i<n+2; i++) {
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++; deg[b]++;
    }
    
    for(int i=1; i<=n; i++) {
        if(deg[i]==4) tb=i;
        else if(deg[i]==3) bh.push_back(i);
    }
    
    vis[tb]=1;
    for(auto to:adj[tb]) {
        dfs(to,to,1);
        // cout << "\n";
    }
    
    dfs1(bh[0], 0);
    
    
    v[1]++; v[2]++;
    cout << v[2] << " " << v[1] << " " << v[0] << "\n";
}