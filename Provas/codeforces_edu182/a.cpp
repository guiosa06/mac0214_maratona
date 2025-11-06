#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n+5];

        int sum=0;
        for(int i=1; i<=n; i++) {
            cin >> a[i];
            sum = (sum+a[i])%3;
        }

        bool flag=0;
        int l=1, r=2, s1=a[1]%3, s2=a[2]%3, s3=(sum+9-s1-s2)%3;
        while(l<n-1) {
            while(r<n) {
                if(s1!=s2 && s2!=s3 && s3!=s1) {
                    flag=1;
                    break;
                }
                else if(s1==s2 && s2==s3 && s3==s1) {
                    flag=1;
                    break;
                }

                r++;
                s2 = (s2+a[r])%3;
                s3 = (s3+3-(a[r]%3))%3;
            }

            if(flag) break;

            l++; r=l+1;
            s1 = (s1+a[l])%3;
            s2 = a[l+1]%3;
            s3 = (sum+9-s1-s2)%3;
        }

        if(flag) {
            cout << l << " " << r << "\n";
        }
        else cout << "0 0" << "\n";
    }
}