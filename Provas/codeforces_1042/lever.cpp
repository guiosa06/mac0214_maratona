#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n+1], b[n+1];
        for(int i=0; i<n; i++) cin >> a[i];
        int sum=0;
        for(int i=0; i<n; i++) {
            cin >> b[i];
            if(a[i]>b[i]) sum += (a[i]-b[i]);
        }
        cout << sum+1 << "\n";
    }
    return 0;
}