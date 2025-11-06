#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n,k; cin >> n >> k;
        int prot=0, l=0, tot=0;

        string s; cin >> s;
        if(s[0]=='1') { tot++; prot++; }

        for(int i=1; i<min(n,k); i++) {
            if(tot==0 && s[i]=='1') prot++;
            if(s[i]=='1') tot++;
        }

        for(int i=k; i<n; i++) {
            if(s[l]=='1') tot--;
            l++;

            if(tot==0 && s[i]=='1') prot++;
            if(s[i]=='1') tot++;
        }

        cout << prot << "\n";
    }
    return 0;
}