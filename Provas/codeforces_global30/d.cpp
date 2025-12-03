#include <bits/stdc++.h>
using namespace std;
    
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while(t--) {
        int n,km; cin >> n >> km;
        string s,t; cin >> s >> t;
    
        int maxD=0;
        vector<int> andar(n,0);
        bool flag=0;
        int menorj=n-1;
    
        for(int i=n-1; i>=0; i--) {
            int j=min(i,menorj);
            // cout << menorj << " " << j << " ";
            int dist=i-j;
            while(j>=0 && s[j]!=t[i]) {
                dist++;
                j--;
            }
            if(j<0) { flag=1; break; }
            andar[j]=max(andar[j],dist);
            
            menorj = j;
            maxD = max(maxD, dist);
            // cout << j << "\n";
        }
        // cout << "\n";
        // for(int i=0; i<n; i++) {
        //     cout << andar[i] << " ";
        // }
        // cout << "\n";
    
        if(flag || maxD>km) {
            cout << -1 << "\n";
            continue;
        }
    
        cout << maxD << "\n";
    
        vector<char> s1(n); s1[0] = s[0];
        for(int k=0; k<maxD; k++) {
            // for(int i=0; i<n; i++) {
            //     cout << andar[i];
            // }
            // cout << "\n";
            vector<int> andar1(n,0);
            for(int i=0; i<n-1; i++) {
                if(andar[i]>0) {
                    s1[i+1] = s[i];
                    andar1[i+1] = andar[i]-1;
                }
                else {
                    s1[i+1] = s[i+1];
                }
            }
    
            for(int i=0; i<n; i++) {
                s[i]=s1[i];
                andar[i] = andar1[i];
                cout << s[i];
            }
            cout << "\n";
        }
        
    }
}