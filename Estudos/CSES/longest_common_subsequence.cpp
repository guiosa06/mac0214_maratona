#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e3+5;

int dp[MAXN][MAXN];
// dp[i][j] = length of longest common subsequence in a[1...i], b[1...j]
bool on[MAXN][MAXN];
// on[i][j] = is a[i]/b[j] in the common subsequence associated to dp[i][j]
pair<int,int> last[MAXN][MAXN];

int main() {
    int n, m; cin >> n >> m;
    int a[n+1], b[m+1];
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=m; i++) cin >> b[i];

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            dp[i][j] = dp[i-1][j-1];
            if(a[i]==b[j]) {
                dp[i][j]++;
                on[i][j]=1;
            }
            if(on[i-1][j-1]) last[i][j]={i-1,j-1};
            else last[i][j]=last[i-1][j-1];
            
            if(dp[i][j] < dp[i][j-1]) {
                dp[i][j] = dp[i][j-1];
                if(on[i][j-1]) last[i][j]={i,j-1};
                else last[i][j]=last[i][j-1];
                on[i][j]=0;
            }
            if(dp[i][j] < dp[i-1][j]) {
                dp[i][j] = dp[i-1][j];
                if(on[i-1][j]) last[i][j]={i-1,j};
                else last[i][j]=last[i-1][j];
                on[i][j]=0;
            }

        }
    }

    cout << dp[n][m] << "\n";
    stack<int> s;
    int I=n, J=m;
    while(dp[I][J]!=0) {
        if(on[I][J]) s.push(a[I]);
        auto [I1,J1] = last[I][J];
        I=I1, J=J1;
    }

    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}