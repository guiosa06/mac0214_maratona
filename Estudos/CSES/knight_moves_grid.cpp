#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef pair<int,int> pii;

int ni[8] = {2,2,-2,-2,1,-1,1,-1};
int nj[8] = {1,-1,1,-1,2,2,-2,-2};

int main() {
    int n; cin >> n;
    int m[n][n];
    for(int i=0; i<n; i++) 
        for(int j=0; j<n; j++)
            m[i][j] = -1;

    queue<pii> q;
    m[0][0]=0;
    q.push({0,0});
    while(!q.empty()) {
        int i=q.front().F, j=q.front().S;
        q.pop();

        for(int k=0; k<8; k++) {
            int i1 = i+ni[k], j1 = j+nj[k];
            if(i1>=0 && i1<n && j1>=0 && j1<n) 
                if(m[i1][j1]==-1) {
                    m[i1][j1] = m[i][j]+1;
                    q.push({i1,j1});
                }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }
}