#include <bits/stdc++.h>
using namespace std;
const int LOGMAX = 32;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while(t--) {
        int a,b; cin >> a >> b;
        vector<int> op;
        bool flag=0;
        for(int i=0; i<LOGMAX; i++) {
            int bita = (1<<i)&a;
            int bitb = (1<<i)&b;

            if(bita!=bitb) {
                if((1<<i)>a) {
                    cout << -1 << "\n";
                    flag=1;
                    break;
                }
                else {
                    op.push_back(1<<i);
                }
            }
        }

        if(!flag) {
            cout << op.size() << "\n";
            for(auto x:op) cout << x << " " ;
            cout << "\n";
        }
    }
}