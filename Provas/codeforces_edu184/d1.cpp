#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        long long x,y,k; cin >> x >> y >> k;
        if(y==1) {
            cout << -1 << "\n";
            continue;
        }

        bool flag=0;

        for(long long i=0; i<x; i++) {
            long long ktmp = k + ((k-1)/(y-1));

            if(ktmp==k) {
                cout << k << "\n";
                flag=1;
                break;
            }
            else if(ktmp>1e12) {
                cout << -1 << "\n";
                flag=1;
                break;
            }
            k = ktmp;
        }

        if(!flag) cout << k << "\n";
    }
    return 0;
}