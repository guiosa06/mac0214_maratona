#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int w=n,l=0;
        long long tot=0;

        while(w>1 || l>1) {
            tot += (long long)(w/2+l/2);
            l=(l+1)/2;
            l+=w/2;
            w=(w+1)/2;
        }

        cout << tot+1 << "\n";
    }
}