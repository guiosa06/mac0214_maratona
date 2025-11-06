#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n+1], b[n+1];
        for(int i=1; i<=n; i++) {
            cin >> a[i];
        }
        for(int i=1; i<=n; i++) {
            cin >> b[i];
        }

        int dp0[n+1], dp1[n+1];
        dp0[1] = 1, dp1[1] = 1;
        for(int i=2; i<=n; i++) {
            dp0[i] = 0, dp1[i] = 0;
            if(a[i-1]<=a[i] && b[i-1]<=b[i]) {
                dp0[i] = (dp0[i]+dp0[i-1])%MOD;
                dp1[i] = (dp1[i]+dp1[i-1])%MOD;
            }
            if(a[i-1]<=b[i] && b[i-1]<=a[i]) {
                dp0[i] = (dp0[i]+dp1[i-1])%MOD;
                dp1[i] = (dp1[i]+dp0[i-1])%MOD;
            }
        }
        
        cout << (dp0[n]+dp1[n])%MOD << "\n";
    }
}