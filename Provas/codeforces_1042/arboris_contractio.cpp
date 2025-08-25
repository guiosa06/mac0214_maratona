#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> adj[n+1];
        int deg[n+1];
        for(int i=0; i<=n; i++) deg[i]=0;

        for(int i=0; i<n-1; i++) {
            int a,b; cin >> a >> b;
            deg[a]++; deg[b]++;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        if(n==2) { cout << 0 << "\n"; continue; }

        int leaves=0, maxDeg=0; 
        int degLeaf[n+1];
        for(int i=0; i<=n; i++) degLeaf[i]=0;
        for(int i=1; i<=n; i++) {
            if(deg[i]==1) {
                leaves++;
                degLeaf[adj[i][0]]++;
                maxDeg = max(maxDeg, degLeaf[adj[i][0]]);
            }
        }

        leaves-=maxDeg;
        cout << leaves << "\n";
    }

    return 0;
}