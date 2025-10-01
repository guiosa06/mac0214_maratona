#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m; cin >> n >> m;
    char g[n+1][m+1];
    for(int i=0; i<=n; i++) g[i][0]='E';
    for(int j=0; j<=m; j++) g[0][j]='E';

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> g[i][j];

            bool possible[5]={1,1,1,1,1};
            possible[(int)(g[i-1][j]-'A')]=0;
            possible[(int)(g[i][j-1]-'A')]=0;
            possible[(int)(g[i][j]-'A')]=0;
            for(int p=0; p<4; p++) {
                if(possible[p]) {
                    g[i][j] = (char)('A'+p);
                    break;
                }
            }
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cout << g[i][j];
        }
        cout << "\n";
    }
}