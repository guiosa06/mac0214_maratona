#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; ll k; cin >> n >> k;
        ll q[n], r[n];
        for(int i=0; i<n; i++) cin >> q[i];
        for(int i=0; i<n; i++) cin >> r[i];

        sort(q, q+n);
        sort(r, r+n);

        int L=0, R=n-1, tot=0;
        while(L<n && R>=0) {
            if(ll((r[L]+1)*q[R] + r[L]) <= k) {
                tot++;
                L++;
                R--;
            }
            else R--;
        }

        cout << tot << "\n";
    }
}