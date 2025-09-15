#include <bits/stdc++.h>
using namespace std;
int main() {

    string s; cin >> s;
    int G[2], P[2], server=0;
    G[0]=0; G[1]=0; P[0]=0; P[1]=0;
    for(int i=0; i<s.size()-1; i++) {
        if(s[i]=='Q') {
            cout << G[0] << " (" << P[0];
            if(server==0) cout << "*";
            cout << ") - " << G[1] << " (" << P[1];
            if(server==1) cout << "*";
            cout << ")\n";
            continue;
        }

        if(s[i]=='S') {
            P[server]++;
        }
        else {
            P[!server]++;
            server = !server;
        }

        if(P[0]==10 || (P[0]>=5 && P[0]-P[1]>=2)) {
            P[0]=P[1]=0;
            G[0]++;
        }
        else if(P[1]==10 || (P[1]>=5 && P[1]-P[0]>=2)) {
            P[0]=P[1]=0;
            G[1]++;
        }
    }
    if(s[s.size()-1]=='Q') {
        if(G[0]==2) {
            cout << G[0] << " (winner) - " << G[1] << "\n";
        }
        else {
            cout << G[0] << " - " << G[1] << " (winner)\n";
        }
    }
    return 0;
}