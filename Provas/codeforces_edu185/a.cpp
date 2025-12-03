#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;

int I[4] = {0,0,1,-1}, J[4] = {1,-1,0,0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int grid[n+2][n+2];

        for(int i=0; i<=n+1; i++) {
            for(int j=0; j<=n+1; j++) {
                grid[i][j]=0;
            }
        }

        int cont=1;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                grid[i][j]=cont++;
            }
        }

        int maxSum=0;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                int mySum = grid[i][j];
                for(int k=0; k<4; k++) mySum+=grid[i+I[k]][j+J[k]];

                maxSum = max(maxSum, mySum);
            }
        }

        cout << maxSum << "\n";
    }
}