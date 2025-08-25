#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    long long d; int c,r;
    cin >> d >> c >> r;
    long long C[c+1], R[r+1];

    for(int i=0; i<c; i++) cin >> C[i];
    for(int i=0; i<r; i++) cin >> R[i];

    int I=0, J=0, resp=0;
    while(true) {
        if(I<c && d>=C[I]) {
            d = d-C[I];
            resp++; I++;
        }
        else if(J<r) {
            d = d+R[J];
            resp++; J++;
        }
        else break;
    }

    cout << resp << "\n";
    return 0;
}