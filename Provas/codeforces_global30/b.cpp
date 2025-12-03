#include <bits/stdc++.h>
using namespace std;
    
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n];
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        bool flag=0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if((a[j]%a[i])%2==0) {
                    cout << a[i] << " " << a[j] << "\n";
                    flag=1;
                    break;
                }
            }
            if(flag) break;
        }
        if(!flag) cout << -1 << "\n";
    }
}