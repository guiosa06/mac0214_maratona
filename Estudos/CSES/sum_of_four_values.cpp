#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main() {
    int n; ll x; cin >> n >> x;
    map<ll, pii> m;
    ll a[n+5];

    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<n; i++) {
        for(int j=i+1; j<=n; j++) {
            int y = x-a[i]-a[j];
            if(m[y].second!=0) {
                if(m[y].first!=i && m[y].first!=j && m[y].second!=i && m[y].second!=j) {
                    cout << m[y].first << " " << m[y].second << " " << i << " " << j << "\n";
                    return 0;
                }
            } 
            if(m[a[i]+a[j]].first == 0) m[a[i]+a[j]] = {i,j};
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}