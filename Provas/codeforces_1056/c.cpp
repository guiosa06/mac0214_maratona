#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n];

        bool flag=0;
        for(int i=0; i<n; i++) {
            cin >> a[i];
            if(i>0 && abs(a[i]-a[i-1]) > 1) flag=1;
        }

        if(flag) {
            cout << 0 << "\n";
            continue;
        }

        int ans=0; 
        bool b[n];
        int pref[n], suf[n];
        for(int j=0; j<=1; j++) {

            b[0]=j; flag=0;

            for(int i=1; i<n; i++) {
                if(abs(a[i]-a[i-1]) == 1) b[i] = b[i-1];
                else b[i] = !b[i-1];
            }

            pref[0]=0; suf[n-1]=0;
            for(int i=1; i<n; i++) 
                pref[i] = pref[i-1] + (!b[i-1] ? 1 : 0);
            for(int i=n-2; i>=0; i--)
                suf[i] = suf[i+1] + (b[i+1] ? 1 : 0);
            
            for(int i=0; i<n; i++)
                if(a[i] != (1+pref[i]+suf[i])) flag=1;

            if(!flag) ans++;
        }

        cout << ans << "\n";
    }
}