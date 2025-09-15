#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--) {
        ll k,x; cin >> k >> x;
        for(int i=0; i<k; i++) {
            x*=2;
        }
        cout << x << "\n";
    }
    return 0;
}