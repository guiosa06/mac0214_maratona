#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[21][21];
int n,m;

int main() {
    ll k; cin >> n >> m >> k;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) cin >> a[i][j];

    if(n+m==2) {
        cout << (k==a[0][0]? 1 : 0) << "\n";
        return 0;
    }

    int mid = (n+m-2)/2;
    vector<vector<map<ll,ll>>> left(n, vector<map<ll, ll>>(m));

    for(int i=0; i<(1<<mid); i++) {
        int iat=0, jat=0;
        ll xorsum = a[iat][jat];
        for(int j=0; j<mid; j++) {
            if(i&(1<<j)) {
                iat++;
                if(iat>n-1) break;
            }
            else {
                jat++;
                if(jat>m-1) break;
            }
            xorsum ^= a[iat][jat];
        }
        if(iat<n && jat<m) left[iat][jat][xorsum]++;
    }

    ll tot=0;
    mid = n+m-2-mid-1;

    for(int i=0; i<(1<<mid); i++) {
        int iat=n-1, jat=m-1;
        ll xorsum = a[iat][jat];
        for(int j=0; j<mid; j++) {
            if(i&(1<<j)) {
                iat--;
                if(iat<0) break;
            }
            else {
                jat--;
                if(jat<0) break;
            }
            xorsum ^= a[iat][jat];
        }
        if(iat>0 && jat>=0) {
            tot += (left[iat-1][jat][k^xorsum]);
        }
        if(jat>0 && iat>=0) {
            tot += (left[iat][jat-1][k^xorsum]);
        }
    }

    cout << tot << "\n";
    
}