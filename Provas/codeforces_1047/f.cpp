#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2*1e5+5;

int a[MAX], b[MAX];

// USANDO BIBLIOTECA DO BRUNOMALETTA
namespace segT {
	ll seg[4*MAX], lazy[4*MAX];
	int n, *v;

	ll build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = max(build(2*p, l, m),build(2*p+1, m+1, r));
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return max(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	ll update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= b) {
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = max(update(a, b, x, 2*p, l, m), update(a, b, x, 2*p+1, m+1, r));
	}
};

using namespace segT;

int get_right(int a, int b, int val, int p=1, int l=0, int r=n-1) {
	if (b < l or r < a or seg[p] < val) return -1;
	if (r == l) return l;
	int m = (l+r)/2;
	int x = get_right(a, b, val, 2*p+1, m+1, r);
	if (x != -1) return x;
	return get_right(a, b, val, 2*p, l, m);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--) {
        int N; cin >> N;
        for(int i=0; i<N; i++) cin >> a[i];
        for(int i=0; i<N; i++) cin >> b[i];

        build(N,a);

        ll sum=0;

        for(int i=0; i<n; i++) {
            if(a[i]==b[i]) {
                sum+=(i+1)*(long long)(n-i);
            }
            else {
                int j=-1;
                if(i>0) j=get_right(0, i-1, max(b[i],a[i]));
                sum += (j+1)*(long long)(n-i);
            }
        }

        cout << sum << "\n";
    }
    return 0;
}