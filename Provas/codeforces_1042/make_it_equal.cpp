#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        map<int,int> rS, rT;
        for(int i=0; i<n; i++) {
            int s; cin >> s;
            rS[s%k]++;
            rS[k-s%k]++;
        }
        for(int i=0; i<n; i++) {
            int t; cin >> t;
            rT[t%k]++;
            rT[k-t%k]++;
        }
        bool flag=0;
        for(auto p:rS) {
            if(rT[p.first]!=p.second) flag=1;
        }
        if(flag) cout << "NO\n";
        else cout << "YES\n";

    }
    return 0;
}