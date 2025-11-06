#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while(t--) {
        int n,m; cin >> n >> m;
        bool flag=0;
        int freq[n+5]; for(int i=0; i<n+5; i++) freq[i]=0;
        int freqR[n+5]; for(int i=0; i<n+5; i++) freqR[i]=0;
        int freqL[n+5]; for(int i=0; i<n+5; i++) freqL[i]=0;
        int p[n+1]; for(int i=0; i<=n; i++) p[i]=-1;
    
        for(int i=0; i<m; i++) {
            int l,r; cin >> l >> r;
            freq[l]++;
            freq[r+1]--;
            freqL[l]++;
            freqR[r]++;
        }

        for(int i=1; i<=n; i++) {
            freq[i] = freq[i]+freq[i-1];
            if(freq[i]==m) {
                p[i]=0;
                int aux=1;
                for(int j=1; j<=n; j++) {
                    if(j==i) continue;
                    p[j]=aux++;
                }
                flag=1;
                break;
            }
        }

        if(!flag) {
            for(int i=1; i<=n; i++) {
                if(freqL[i]>0 && freqR[i]>0) continue;
                else {
                    int i1;
                    if(freqL[i]>0) i1=i+1; 
                    else i1=i-1;

                    if(i1>n || i1<1) continue;

                    p[i] = 0; p[i1]=1;
                    int aux=2;
                    for(int j=1; j<=n; j++) {
                        if(j==i || j==i1) continue;
                        p[j] = aux++;
                    }
                    flag=1;
                    break;
                }
            }

        }

        if(!flag) {
            p[1]=0; p[2]=2, p[3]=1;
            int aux=3;
            for(int j=4; j<=n; j++) {
                p[j] = aux++;
            }
        }


        for(int i=1;  i<=n; i++) cout << p[i] << " ";
        cout << "\n";
    }
}