#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2*1e5+5;

int a[MAXN], b[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--) {
        bool flag=0;

        int n; cin >> n;
        int freq[n+1], last[n+1], cont[n+1];
        for(int i=0; i<=n; i++) {
            freq[i]=0;
            last[i]=0;
            cont[i]=0;
        }
        for(int i=0; i<n; i++) {
            cin >> b[i];
            freq[b[i]]++;
        }
        for(int i=1; i<=n; i++) {
            if(freq[i]%i!=0) {
                flag=1;
            }
        }

        if(flag) cout << -1;
        else {
            int at=1;
            for(int i=0; i<n; i++) {
                if(cont[b[i]]==0) {
                    cont[b[i]]++;
                    last[b[i]] = a[i] = at++;
                } 
                else {
                    cont[b[i]]++;
                    a[i] = last[b[i]];
                }
                if(cont[b[i]]==b[i]) {
                    cont[b[i]]=0;
                }
            }

            for(int i=0; i<n; i++) {
                cout << a[i] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}