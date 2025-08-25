#include <bits/stdc++.h>
using namespace std;

struct par {
    int n,c;
};

int main() {
    int n,k; cin >> n >> k;
    int posColor[n+1];
    par pairs[n+1];
    for(int i=1; i<=n; i++) {
        int N,C; cin >> N >> C;
        pairs[i] = {N,C};
        posColor[i] = C;
    }    

    bool flag=0;
    for(int i=1; i<=n; i++) {
        if(posColor[pairs[i].n] != pairs[i].c) flag=1;
    }

    if(flag) cout << "N\n";
    else cout << "Y\n";
    return 0;
}