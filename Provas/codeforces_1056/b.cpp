#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        char g[n+2][n+2];

        if(k==n*n-1) cout << "NO\n";    
        else {
            cout << "YES\n";

            for(int i=1; i<=n; i++) {
                for(int j=1; j<=n; j++) {
                    if(k>0) {
                        g[i][j]='L';
                        k--;
                    }
                    else {
                        if(i<n) g[i][j]='D';
                        else {
                            if(j<n) g[i][j]='R';
                            else g[i][j]='L';
                        }
                    }
                }
            }
        
            for(int i=1; i<=n; i++) {
                for(int j=1; j<=n; j++) {
                    cout << g[i][j];
                }
                cout << "\n";
            }
        }
    }
}