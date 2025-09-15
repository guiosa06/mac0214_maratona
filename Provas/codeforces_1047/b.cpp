#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2*1e5+5;

int p[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        for(int i=0; i<n; i++) {
            cin >> p[i];
            cout << n-p[i]+1 << " ";
        }
        cout << "\n";
    }
    return 0;
}