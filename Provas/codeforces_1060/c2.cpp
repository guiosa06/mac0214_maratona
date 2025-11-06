#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2*1e5+2;
const ll INF = 1e18;

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
        int a[n+1], a1[n+1], a2[n+1];
        ll b[n+1];
        for(int i=0; i<n; i++) {
            cin >> a[i];
            a1[i]=a[i]+1;
            a2[i]=a[i]+2;
        }
        ll menorb = INF, bbzinho;
        for(int i=0; i<n; i++) {
            cin >> b[i];
            if(b[i]<menorb) {
                menorb = b[i];
                bbzinho=i;
            }
        }

        vector<int> cont(MAXN, 0);
        vector<int> cont1(MAXN, 0);

        vector<int> fat[n], fat1[n], fat2[n];
        bool flag=0;
        ll resp=INF;
        set<int> primes;

        for(int i=0; i<n; i++) {
            if(a[i]!=1) {
                fact(fat[i], a[i]);
                for(auto x:fat[i]) {
                    if(cont[x]>0 && cont[x]!=(i+1)) {
                        resp=0;
                        flag=1;
                        break;
                    }
                    if(cont1[x]>0 && cont1[x]!=(i+1)) {
                        resp=min(resp, b[cont1[x]-1]);
                    }

                    cont[x] = i+1;
                    primes.insert(x);
                }
                if(flag) break;
            }
            
            fact(fat1[i], a1[i]);
            for(auto x:fat1[i]) {
                if(cont[x]>0 && cont[x]!=(i+1)) {
                    resp=min(resp, b[i]);
                }
                if(cont1[x]>0 && cont1[x]!=(i+1)) {
                    resp=min(resp, b[i]+b[cont1[x]-1]);
                }

                if(cont1[x]<=0) cont1[x]=i+1;
                else if(b[i]<b[cont1[x]-1]) {
                    cont1[x]=i+1;
                }
            }

        }
        for(auto x:primes) {
            if(a[bbzinho]%x!=0) {
                resp = min(resp, b[bbzinho]*(x-(a[bbzinho]%x)));
            }
        }

        cout << resp << "\n";
        
    }
    return 0;
}