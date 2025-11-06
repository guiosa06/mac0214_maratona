#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;

        int A=0,B=0;
        for(auto c:s) {
            if(c=='a') A++;
            else B++;
        }
 
        if(A==B) {
            cout << 0 << "\n";
            continue;
        }

        int dif=A-B;

        int pref[n+1]; pref[0]=0;
        map<int,int> m;

        int resp=INF;
        for(int i=1; i<=n; i++) {
            pref[i] = pref[i-1]+(s[i-1]=='a' ? 1 : -1);

            if(dif==pref[i]) resp = min(resp, i);
            if(m[pref[i]-dif]>0) resp = min(resp, i-m[pref[i]-dif]);
            m[pref[i]]=i;

            //cout << pref[i] << " " << resp << "\n";
        }
        
        if(resp==n) cout << -1;
        else cout << resp;
        cout << "\n";
    }
    
    return 0;
}