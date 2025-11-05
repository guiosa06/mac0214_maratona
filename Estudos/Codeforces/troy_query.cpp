#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5+2;

map<ll, int> m1;
map<ll, int> m2;

int pai[4*MAXN], h[4*MAXN];
int find(int a) {
    if(pai[a] == a) return a;
    else return pai[a]=find(pai[a]);
}
void unite(int a, int b) {
    int ra=find(a), rb=find(b);
    if(ra==rb) return;
    if(h[ra]<=h[rb]) {
        pai[ra]=rb;
        h[rb] = max(h[rb], h[ra]+1);
    }
    else {
        pai[rb]=ra;
        h[ra] = max(h[ra], h[rb]+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for(int i=1; i<4*MAXN; i++) {
        pai[i]=i;
        h[i]=1;
    }

    int n; cin >> n;
    bool flag=0;
    int x=1,y=1;

    for(int i=0; i<n; i++) {
        ll X, Y; int a,b;
        cin >> X >> Y >> a >> b;

        if(flag) {
            cout << "No\n";
            continue;
        }


        if(m1[X]>0) X = m1[X];
        else X = m1[X] = x++;

        if(m2[Y]>0) Y = m2[Y];
        else Y = m2[Y] = y++;


        if(a==b) {
            unite(2*X-1, 2*Y-1+2*n);
            unite(2*X, 2*Y+2*n);
        }
        else {
            unite(2*X-1, 2*Y+2*n);
            unite(2*X, 2*Y-1+2*n);
        }


        if(find(2*X-1) == find(2*X)) {
            cout << "No\n";
            flag=1;
        }
        else cout << "Yes\n";
    }
}