#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll t[41];
vector<ll> all_sums(int p, int r) {
    vector<ll> resp;

    if(p>r) return resp={0};

    int n = r-p+1;
    for(int i=0; i<(1<<n); i++) {
        ll sum = 0;
        for(int j=0; j<n; j++) 
            if(i&(1<<j)) sum+=t[j+p];
        resp.push_back(sum);
    }

    return resp;
}

int main() {
    int n,x; cin >> n >> x;
    for(int i=0; i<n; i++) cin >> t[i];

    vector<ll> left = all_sums(0,n/2-1);
    vector<ll> right = all_sums(n/2, n-1);

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    ll tot=0;
    for(auto l:left) {
        auto lowB = lower_bound(right.begin(), right.end(), x-l);
        auto uppB = upper_bound(right.begin(), right.end(), x-l);
        tot += (ll)(uppB-lowB);
    }

    cout << tot << "\n";
    return 0;
}