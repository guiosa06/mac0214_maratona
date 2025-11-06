#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2*1e6;
typedef long long ll;
const ll INF=1e18;

ll cnt[MAXN], pref[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while(t--) {
        for(int i=0; i<MAXN; i++) cnt[i]=0;

        int n; ll y; cin >> n >> y;
        int a[n+1], A=0;

        for(int i=0; i<n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
            A = max(A,a[i]);
        }

        if(A==1) {
            cout << n << "\n";
            continue;
        }

        for(int i=1; i<MAXN; i++) pref[i]=pref[i-1]+cnt[i];

        ll ans=-INF;
        for(int x=2; x<=A; x++) {
            ll aux=0; 
            for(int p=1; p<=(A+x-1)/x; p++) {
                ll totp = pref[p*x]-pref[(p-1)*x];
                ll imprimir = max(0LL,totp-cnt[p]);
                aux += (totp*p - imprimir*y);
            }

            ans = max(ans, aux);
            //cout << x << ": " << aux << "\n";
        }

        cout << ans << "\n";
    }
    
    return 0;
}