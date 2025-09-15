#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2*1e5+5;

int a[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        int freq[n+1];
        for(int i=0; i<=n; i++) {
            freq[i]=0;
        }

        for(int i=0; i<n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }
        int mex = 0;
        for(int i=0; i<=n; i++) {
            if(freq[i]==0) {
                mex=i;
                break;
            }
        }

        for(int i=0; i<n; i++) {
            if(a[i]>mex) a[i]=mex;
            else if(freq[a[i]]>1) {
                a[i]=mex;
            }
        }
        for(int i=0; i<n; i++) {
            freq[i]=0;
        }
        for(int i=0; i<n; i++) {
            freq[a[i]]++;
        }

        ll aux=0;

        if(k>=2) {
            bool flag=0;
            for(int i=0; i<mex; i++) {
                if(freq[i]==0) {
                    mex=i;
                    flag=1;
                    break;
                }
            }

            if(flag) {
                for(int i=0; i<n; i++) {
                    if(a[i]>mex) a[i]=mex;
                    else if(freq[a[i]]>1) {
                        a[i]=mex;
                    }
                }
                k--;
            }
            
            if(k%2==0) aux=1;
            if(mex==n-1) aux=0;
        }

        ll sum=0;
        for(int i=0; i<n; i++) {
            sum+=1LL*a[i];
            if(a[i]==mex) sum+=aux;
        }

        cout << sum << "\n";
    }
    return 0;
}