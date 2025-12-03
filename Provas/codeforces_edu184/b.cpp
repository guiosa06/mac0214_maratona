#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int n=s.size();
        bool flag=0;
        for(int i=0; i<n-1; i++) {
            char c = s[i], d = s[i+1];
            if(c=='>' && d=='<') flag=1;
            else if(c=='>' && d=='*')flag=1;
            else if(c=='*' && d=='<')flag=1;
            else if(c=='*' && d=='*')flag=1;
        }
        if(flag) {cout << -1 << "\n"; continue;}

        int idx=0, tot1=0, tot2=0, aux=0;
        while(idx<n && s[idx]=='<') {
            tot1++;
            idx++;
        }
        if(idx<n && s[idx]=='*') {
            aux=1;
            idx++;
        }
        while(idx<n && s[idx]=='>') {
            tot2++;
            idx++;
        }
        cout << max(tot1+aux, tot2+aux) << "\n";
    }
    return 0;
}