#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while(t--) {
        int n,k; cin >> n >> k;
        int a[n+k], freq[n+1], dif=0;
        for(int i=0; i<=n; i++) {
            freq[i]=0;
        }
        for(int i=0; i<n; i++) {
            cin >> a[i];
            freq[a[i]]++;
            if(freq[a[i]]==1) dif++;
        }
        int at;
        if(dif==n) at = a[0];
        else {
            for(int i=1; i<=n; i++) {
                if(freq[i]==0) at = i;
            }
        }

        cout << at << " ";
        int last=a[n-1], next;
        for(int i=0; i<k-1; i++) {
            next = (last)%n+1;
            if(next==at) next = (next)%n+1;
            cout << next << " ";

            last = at;
            at = next;
        }
        cout << "\n";
    }
}