#include <bits/stdc++.h>
using namespace std;

int m[100][100];
int main() {

    for(int i=0; i<100; i++) {
        m[i][0]=i;
        for(int j=1; j<100; j++) {
            vector<int> freq(1000);
            for(int ii=0; ii<i; ii++) freq[m[ii][j]] = 1;
            for(int jj=0; jj<j; jj++) freq[m[i][jj]] = 1;
            for(int k=0; k<1000; k++)
                if(!freq[k]) { m[i][j]=k; break; }
        }
    }

    int n; cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            cout << m[i][j] << " ";
        cout << "\n";
    }

    return 0;
}