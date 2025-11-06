#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int m=0;
        for(int i=0; i<n; i++) {
            int a; cin >> a;
            m = max(m,a);
        }

        cout << m << "\n";
    }
}