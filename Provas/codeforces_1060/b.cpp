#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n+10];
        int maior=0, resp=0;

        for(int i=0; i<n; i++) {
            cin >> a[i];
            maior=max(maior,a[i]);
            if(i%2==1) a[i]=maior;
        }

        for(int i=0; i<n; i++) {

            if(i%2==1) {
                if(a[i-1]==a[i]) {
                    resp++;
                }
                if(i<n-1 && a[i+1]>=a[i]) {
                    resp += (a[i+1]-a[i]+1);
                    a[i+1] -= (a[i+1]-a[i]+1);
                }
            }
        }

        cout << resp << "\n";
    }

    return 0;
}