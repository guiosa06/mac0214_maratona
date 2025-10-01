#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e18;

int main() {
    int n,t; cin >> n >> t;
    ll k[n];
    for(int i=0; i<n; i++) cin >> k[i];

    ll l=0, r=INF;
    while(l<r-1) {
        ll m = (l+r)/2;
        ll tot=0;
        for(int i=0; i<n; i++) {
            tot += (m/k[i]);
            if(tot>t) break;
        }
        if(tot<t) l=m;
        else if(tot>=t) r=m;

    }

    cout << r << "\n";
    return 0;
}