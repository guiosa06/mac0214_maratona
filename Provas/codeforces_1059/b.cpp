#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<int> idx;
        for(int i=0; i<n; i++) {
            if(s[i]=='1') idx.push_back(i+1);
        }

        cout << idx.size() << "\n";
        for(auto a:idx) cout << a << " ";
        cout << "\n";
    }
}