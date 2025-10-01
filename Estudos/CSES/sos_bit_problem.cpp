#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2*1e5+5;
const int LGMAX = 20;

int x[MAXN];
vector<ll> freq(1<<20);

// sum over sub-sets
vector<ll> sosub_dp(vector<ll> f) {
	int N = __builtin_ctz(f.size());
	assert((1<<N) == f.size());

	for (int i = 0; i < N; i++) for (int mask = 0; mask < (1<<N); mask++)
		if (mask>>i&1) f[mask] += f[mask^(1<<i)];
	return f;
}

// sum over super-sets 
vector<ll> sosup_dp(vector<ll> f) {
	int N = __builtin_ctz(f.size());
	assert((1<<N) == f.size());

	for (int i = 0; i < N; i++) for (int mask = 0; mask < (1<<N); mask++)
		if (~mask>>i&1) f[mask] += f[mask^(1<<i)];
	return f;
}

int main() {
    int n; cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x[i];
        freq[x[i]]++;
    }

    vector<ll> sos1 = sosub_dp(freq);
    vector<ll> sos2 = sosup_dp(freq);

    for(int i=0; i<n; i++) {
        cout << sos1[x[i]] << " " << sos2[x[i]] << " " << n-sos1[(1<<20)-1-x[i]] << "\n";
    }

    return 0;
}