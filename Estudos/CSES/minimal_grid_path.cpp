#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3005;
pair<int,int> anterior[MAXN][MAXN];
bool inMinPath[MAXN][MAXN];

int main() {
    int n; cin >> n;
    char g[n+1][n+1];

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> g[i][j];
        }
    }

    anterior[1][1]={0,0};
    inMinPath[1][1]=1;
    for(int t=3; t<=2*n; t++) {
        int minChar=100;
        for(int i=max(1, t-n); i<=min(t-1,n); i++) {
            int j=t-i;
            if(inMinPath[i-1][j] || inMinPath[i][j-1])
                minChar = min(minChar, (int)(g[i][j]-'A'));
        }

        for(int i=max(1, t-n); i<=min(t-1,n); i++) {
            int j=t-i;
            if((inMinPath[i-1][j] || inMinPath[i][j-1]) && g[i][j]==(char)(minChar+'A')) {
                inMinPath[i][j]=1;
                if(inMinPath[i-1][j]) anterior[i][j]={i-1,j};
                else anterior[i][j]={i,j-1};
            }
        }
    }

    vector<char> minPath(2*n-1);
    int I=n,J=n;
    for(int k=2*n-2; k>=0; k--) {
        minPath[k] = g[I][J];
        auto [NI,NJ] = anterior[I][J];
        I = NI, J = NJ;
    }

    for(auto c:minPath) cout << c;
    cout << "\n";
    return 0;
}