#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n;
        cin >> n;
        long long a[n+1], sum=0;
        for(int i=1; i<=n; i++) {
            cin >> a[i];
            sum+=a[i];
        }
        long long d0[n+1], d1[n+1];
        d0[0]=0; d1[0]=0;
        for(int i=1; i<=n; i++) {
            d0[i] = max(d0[i-1], (long long)(d1[i-1]+2*i-a[i]));
            d1[i] = max(0LL, (long long)(d1[i-1]+2*i-a[i]));
        }

        cout << sum+d0[n] << "\n";
    }
    return 0;
}