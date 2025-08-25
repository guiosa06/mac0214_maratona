#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=75;

ll fib[MAXN];
map<ll,int> dp;
vector<int> v;

int solve(ll n) {

    if(dp[n]!=0) return dp[n];

    for(int i=MAXN-1; i>0; i--) {
    
        if(n%fib[i]==0 && solve(n/fib[i])==1) {
            v.push_back(i);
            return dp[n] = 1;
        }
        else {
            while(!v.empty()) v.pop_back();
        }
        
    }

    return dp[n] = -1;

}

void write() {
    for(int i=v.size()-1; i>=0; i--) {
        for(int j=0; j<v[i]; j++) {
            cout << "A";
        }
        cout << "B";
    }
    cout << "\n";
}

int main() {
    ll n; cin >> n;
    int ceil=0;

    fib[1]=2; fib[2]=3;
    for(int i=3; i<MAXN; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    dp[1] = 1;
    if(solve(n)==1) write();
    else cout << "IMPOSSIBLE\n";

    return 0;
}