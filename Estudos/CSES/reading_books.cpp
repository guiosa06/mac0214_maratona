#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    ll t[n];
    ll T=0, sum=0;  
    for(int i=0; i<n; i++) {
        cin >> t[i];
        T = max(T,t[i]);
        sum = sum + t[i];
    }

    if(T>sum-T) cout << 2*T << "\n";
    else cout << sum << "\n";

    return 0;
}