#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;

        cout << "1 1 " << n << "\n";
        cout.flush();
        int sumP; cin >> sumP;

        cout << "2 1 " << n << "\n";
        cout.flush();
        int sumA; cin >> sumA;

        int length = sumA-sumP;

        int l1=0,l2=n;
        while(l1<l2-1) {
            int m=(l1+l2)/2;
            cout << "1 1 " << m << "\n";
            cout.flush();

            int x; cin >> x;
            
            cout << "2 1 " << m << "\n";
            cout.flush();

            int y; cin >> y;

            if(x!=y) {
                l2=m;
            }
            else {
                l1=m;
            }
        }

        cout << "! " << l2 << " " << l2+length-1 << "\n";
        cout.flush();
    }
}