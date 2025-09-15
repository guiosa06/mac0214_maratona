#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e3+5;
const ll PARE=31622776;

ll c[MAXN];
vector<pii> adj[MAXN];

ll p[MAXN];
ll pot[51];


ll atual=2;
void check(int i) {
    ll j=c[adj[i][0].first];
    while(j%atual!=0 && atual<=PARE) atual++;

    if(atual>PARE) p[i] = c[adj[i][0].first];
    else p[i]=atual;

    pot[1]=p[i];
    for(int k=2; k<=50; k++) {
        pot[k]=p[i]*pot[k-1];
    }

    for(auto to:adj[i]) {
        int node = to.first; int d = to.second;
        c[node] /= pot[d];
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int M,N,K; cin >> M >> N >> K;
    for(int i=1; i<=N; i++) cin >> c[i];
    for(int i=0; i<K; i++) {
        int m,n,d; cin >> m >> n >> d;
        adj[m].push_back({n,d});
    }

    for(int i=1; i<=M; i++) {
        check(i);
        cout << p[i] << " ";
    }
    cout << "\n";
}