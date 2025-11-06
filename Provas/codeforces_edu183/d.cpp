#include <bits/stdc++.h>
using namespace std;
const int MAXN = 30;
const int MAXM = 15*29;

int dp[MAXN+1][MAXM+1];
// dp[i][j] é > 0 se existe uma permutação de i elementos 
// com exatamente j subarrays ordenados

// ao mesmo tempo, representa tamanho do último bloco ordenado

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    dp[0][0] = 1;
    for(int i=1; i<=MAXN; i++) {
        dp[i][0] = 1;
        for(int j=1; j<=(i*(i-1)/2); j++) {
            for(int k=2; k<=i; k++) {
                if(j-(k*(k-1))/2 < 0) break;
                if(dp[i-k][j-(k*(k-1))/2] > 0) {
                    dp[i][j] = k;
                    break;
                }
            }
        }
    }


    int t; cin >> t;
    while(t--) {
        int n,k; cin >> n >> k;
        int i = n, j = (n*(n-1))/2 - k;
        if(dp[i][j]==0) {
            cout << 0 << "\n";
            continue;
        }
        
        
        while(i>0) {
            int aux = dp[i][j];
            for(int l=i-aux+1; l<=i; l++) cout << l << " ";
            i = i-aux;
            j = j-(aux*(aux-1))/2;
        }
        cout << "\n";
    }
    
    return 0;
}