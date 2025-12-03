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
        }
        sort(a,a+n);
        for(int i=0; i<n-1; i++) {
            if(i%2==1) {
                if(a[i]!=a[i+1]) {
                    flag=1;
                    break;
                }
            }
        }
        if(flag) cout << "NO\n";
        else cout << "YES\n";
    }
}