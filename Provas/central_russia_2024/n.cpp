#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
    
int main(){
    int n; cin >> n;
    vector<string> names(n+1);
    for(int i=0; i<n; i++) cin >> names[i];
    
    bool on[n]; for(int i=0; i<n; i++) on[i]=1;
    int ans=0, at=0, m=names[0].size();
    
    while(at<m) {
        bool flag=0, tab=0;
        while(true) {
            if(at>=m) break;
            for(int i=1; i<n; i++) {
                if(!on[i]) continue;
                if(names[i].size()-1 < at) {
                    flag=1; on[i]=0;
                }
                if(names[i][at]!=names[0][at]) {
                    flag=1; on[i]=0;
                }
            }
    
            if(flag) {
                ans++;
                at++;
                break;
            }
            else {
                tab=1; at++;
            }
        }
        if(tab) ans++;
    }
    
    cout << ans <<"\n";
}