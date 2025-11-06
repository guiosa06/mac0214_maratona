#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2*1e5+3;

// brunomaletta
int divi[MAXN];

void crivo(int lim) {
	for (int i = 1; i <= lim; i++) divi[i] = 1;

	for (int i = 2; i <= lim; i++) if (divi[i] == 1)
		for (int j = i; j <= lim; j += i) divi[j] = i;
}

void fact(vector<int>& v, int n) {
	if (n != divi[n]) fact(v, n/divi[n]);
	v.push_back(divi[n]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    crivo(MAXN);

    int t; cin >> t;
    while(t--) {
        int n;cin >> n;
        int a[n+1], b[n+1], a1[n+1];
        for(int i=0; i<n; i++) {
            cin >> a[i];
            a1[i]=a[i]+1;
        }
        for(int i=0; i<n; i++) cin >> b[i];

        vector<int> cont(MAXN, 0);

        vector<int> fat[n];
        bool flag=0;
        for(int i=0; i<n; i++) {
            if(a[i]==1) continue;
            fact(fat[i], a[i]);
            for(auto x:fat[i]) {
                if(cont[x]>0 && cont[x]!=(i+1)) {
                    cout << 0 << "\n";
                    flag=1;
                    // cout << x << " " << i+1 << " - " << cont[x] << "\n";
                    break;
                }
                cont[x]=i+1;
            }

            if(flag) break;
        }
        if(flag) continue;

        vector<int> fat1[n];
        for(int i=0; i<n; i++) {
            if(a1[i]==1) continue;
            fact(fat1[i], a1[i]);
            for(auto x:fat1[i]) {
                if(cont[x]>0 && cont[x]!=(i+1)) {
                    cout << 1 << "\n";
                    flag=1;
                    break;
                }
            }

            if(flag) break;
        }
        if(flag) continue;

        cout << 2 << "\n";
    }
    return 0;
}