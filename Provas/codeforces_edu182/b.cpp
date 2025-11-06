#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int freq[n+1], p[n+1];
        stack<int> s;

        for(int i=0; i<=n; i++) freq[i]=0;

        for(int i=1; i<=n; i++) {
            cin >> p[i];
            freq[p[i]]++;
        }

        for(int i=1; i<=n; i++) {
            if(freq[i]==0) s.push(i);
        }

        int l=0, r=-1;
        for(int i=1; i<=n; i++) {
            if(p[i]==0) {
                p[i]=s.top();
                s.pop();
            }

            if(p[i]!=i) {
                if(l==0) l=i;
                r=i;
            }
        }

        cout << r-l+1 << "\n";
    }
}