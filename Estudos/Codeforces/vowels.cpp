#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> freq((1<<24));

vector<ll> sos_dp(vector<ll> f) {
    int N = __builtin_ctz(f.size());
    assert((1<<N) == f.size());

    for(int i=0; i<N; i++) for(int mask=0; mask<(1<<N); mask++)
        if(mask>>i&1) f[mask]+=f[mask^(1<<i)];
    return f;
}

int main() {
    ll n; cin >> n;
    for(int i=0; i<n; i++) {
        string s; cin >> s;
        ll word_mask=0;
        for(int j=0; j<s.size(); j++) {
            ll letter = (ll)(s[j]-'a');
            word_mask = word_mask | (1ll<<letter);
        }
        freq[word_mask]++;
    }

    vector<ll> sos = sos_dp(freq);

    ll resp=0;
    for(ll i=0; i<(1<<24); i++) {
        ll aux = n - sos[(1<<24)-1-i];
        resp ^= aux*aux;
    }

    cout << resp << "\n";

    return 0;
}