#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5+5;

ll dp[505][MAXN];
// dp[i][j] = melhor lucro para i barcos colocando o i-ésimo barco terminando até posição j
ll t[MAXN];
ll resp=0;

int main() {
    ll n,g; cin >> n >> g;
    // INDEXANDO EM 1
    for(int i=1; i<=n; i++) {
        cin >> t[i];
    }

    for(int k=1; k*(k+1)<=2*n; k++) {
        int l=(k*(k-1))/2 + 1;
        int r=l+k-1;
        ll sum=0;
        for(int i=l; i<=r; i++) {
            sum+=t[i];
        }
        while(r<=n) {
            dp[k][r] = max(dp[k][r-1], dp[k-1][r-k]-sum+g);
            resp = max(resp, dp[k][r]);

            sum-=t[l++];
            sum+=t[++r];
        }
    }

    cout << resp << "\n";
    
}
