#include <bits/stdc++.h>
using namespace std;
int main() {
    int c; cin >> c;
    int sum=100;
    int resp=100;
    for(int i=0; i<c; i++) {
        int v; cin >> v;
        sum+=v;
        resp = max(resp, sum);
    }

    cout << resp << "\n";
    return 0;
}