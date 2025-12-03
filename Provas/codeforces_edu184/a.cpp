#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while(t--) {
        int n,a; cin >> n >> a;
        int lower=0, higher=0;
        for(int i=0; i<n; i++) {
            int v; cin >> v;
            if(a<v) higher++;
            else if(a>v) lower++;
        }
        if(higher>lower) cout << a+1;
        else cout << a-1;

        cout << "\n";
    }
    return 0;
}