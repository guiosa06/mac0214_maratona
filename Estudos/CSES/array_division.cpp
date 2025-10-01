#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e18;

int main() {

    int n, k; cin >> n >> k;
    ll x[n];
    for(int i=0; i<n; i++) cin >> x[i];

    ll l=0, r=INF;
    while(l<r-1) {
        ll m=(l+r)/2;
        ll sum=0; int subarrays=0;
        for(int i=0; i<n; i++) {
            if(x[i]>m) {
                subarrays=1e9+1;
                break;
            }
            if(sum+x[i]>m) {
                sum=0;
                subarrays++;
            }
            sum+=x[i];
        }
        subarrays++;
        if(subarrays<=k) r=m;
        else l=m; 

    }

    cout << r << "\n";
    return 0;
}