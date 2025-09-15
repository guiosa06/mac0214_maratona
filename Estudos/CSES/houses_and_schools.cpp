#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 3*1e3+5;
const ll INF=1e18;

struct CHT {
	int it;
	vector<ll> a, b;
	CHT():it(0){}
	ll eval(int i, ll x){
		return a[i]*x + b[i];
	}
	bool useless(){
		int sz = a.size();
		int r = sz-1, m = sz-2, l = sz-3;
#warning cuidado com overflow!

		__int128 left  = (__int128)(b[l] - b[r]) * (__int128)(a[m] - a[l]);
		__int128 right = (__int128)(b[l] - b[m]) * (__int128)(a[r] - a[l]);
		return left < right;
	}
	void add(ll A, ll B){
		a.push_back(A); b.push_back(B);
		while (!a.empty()){
			if ((a.size() < 3) || !useless()) break;
			a.erase(a.end() - 2);
			b.erase(b.end() - 2);
		}
		it = min(it, int(a.size()) - 1);
	}
	ll get(ll x){
		while (it+1 < a.size()){
			if (eval(it+1, x) > eval(it, x)) it++;
			else break;
		}
		return eval(it, x);
	}
};

ll c[MAXN];
ll dp0[MAXN][MAXN], dp1[MAXN][MAXN];
ll t[MAXN], p[MAXN], s[MAXN];

int main() {
    int n,k; cin >> n >> k;
	for(int i=1; i<=n; i++) cin >> c[i];

	for(int i=1; i<=n; i++) {
		t[i] = c[i]+t[i-1];
		p[i] = c[i]*i+p[i-1];
	}

	for(int m=0; m<=k; m++){
		for(int i=0; i<=n; i++){
			dp0[m][i] = dp1[m][i] = INF;
		}
	}
	dp0[0][0]=0;
	for(int m=1; m<=k; m++) {
		CHT cht0 = CHT();
		CHT cht1 = CHT();
		cht0.add(0,0);
		for(int i=1; i<=n; i++) {
			dp1[m][i] = -cht0.get(i)+t[i]*i-p[i];
			cht1.add(i, -t[i]*i+p[i]-dp1[m][i]);
			dp0[m][i] = -cht1.get(t[i])+p[i];
			if(dp0[m-1][i]<INF) cht0.add(t[i],-p[i]-dp0[m-1][i]);
		}
	}

	ll resp=INF;
	resp = min(resp, min(dp1[k][n], dp0[k][n]));
	cout << resp << "\n";
}