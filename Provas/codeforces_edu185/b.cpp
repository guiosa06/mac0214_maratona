#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int I[4] = {0,0,1,-1}, J[4] = {1,-1,0,0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        ll b[n];
        ll totPos=0, totSum=0;
        for(int i=0; i<n; i++) {
            cin >> b[i];
            totSum += b[i];
            if(b[i]>0) totPos++;
        }


        for(int i=totPos; i>0; i--) {
            if((totSum - i) >= (n-1)) {
                cout << i << "\n";
                break;
            }
        }
        
    }
}