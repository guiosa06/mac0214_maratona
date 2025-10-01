#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, k; cin >> n >> k;
    int x[n+1];
    for(int i=1; i<=n; i++) cin >> x[i];

    int l=1, r=1; 
    map<int, int> m;
    ll resp = 0;
    int dist=0;
    while(r<=n) {
        if(m[x[r]]==0) {
            dist++;
        }
        m[x[r]]++;

        while(dist>k) {
            m[x[l]]--;
            if(m[x[l]]==0) dist--;
            l++;
        }

        resp += 1LL*(r-l+1);
        r++;
    }

    cout << resp << "\n";
    return 0;
}