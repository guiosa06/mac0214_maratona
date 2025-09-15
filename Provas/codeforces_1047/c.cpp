#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2*1e5+5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--) {
        ll a,b; cin >> a >> b;
        if(a%2==0 && b%2==1) cout << -1;
        else if(a%2==1 && b%2==1) cout << a*b+1;
        else if(a%2==1 && b%2==0) {
            if(b%4==0) {
                cout << a*(b/2) + 2;
            }
            else {
                cout << -1;
            }
        }
        else {
            cout << a*(b/2) + 2;
        }

        cout << "\n";
    }
    return 0;
}