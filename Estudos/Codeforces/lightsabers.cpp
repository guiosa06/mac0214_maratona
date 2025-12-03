#include <bits/stdc++.h>
using namespace std;
const int MOD = 1009;
typedef long long ll;

// cp algo
using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}
vector<ll> multiply(vector<ll> const& a, vector<ll> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<ll> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

class comp {
    public: bool operator()(const vector<ll>& a, const vector<ll>& b) {
        return a.size()>b.size();
    }
};


int main() {
    int n,m,k; cin >> n >> m >> k;
    vector<int> c(n), freq(m+1, 0);
    for(int i=0; i<n; i++) {
        cin >> c[i];
        freq[c[i]]++;
    }

    priority_queue<vector<ll>, vector<vector<ll>>, comp> pq;
    for(int i=1; i<=m; i++) {
        vector<ll> P(min(freq[i]+1, k+1), 1);
        pq.push(P);
    }

    while(pq.size()>1) {
        vector<ll> A = pq.top(); pq.pop();
        vector<ll> B = pq.top(); pq.pop();
        auto mul = multiply(A, B);

        vector<ll> C;
        for(int i=0; i<k+1; i++) {
            if(i>=mul.size()) break;
            C.push_back((ll)(mul[i]+MOD)%MOD);
        }
        pq.push(C);
    }

    if(k>=pq.top().size()) cout << 0;
    else cout << (pq.top()[k] + MOD)%MOD;
    cout << "\n"; 


    return 0;
}