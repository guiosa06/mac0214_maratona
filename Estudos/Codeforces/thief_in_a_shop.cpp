#include <bits/stdc++.h>
using namespace std;
typedef complex<long double> cmplxd;
	
void get_roots(bool f, int n, vector<complex<long double>>& roots) {
	const static long double PI = acosl(-1);
	for (int i = 0; i < n/2; i++) {
		long double alpha = i*((2*PI)/n);
		if (f) alpha = -alpha;
		roots[i] = {cos(alpha), sin(alpha)};
	}
}
	
template<typename T> void fft(vector<T>& a, bool f, int N, vector<int>& rev) {
	for (int i = 0; i < N; i++) if (i < rev[i]) swap(a[i], a[rev[i]]);
	int l, r, m;
	vector<T> roots(N);
	for (int n = 2; n <= N; n *= 2) {
		get_roots(f, n, roots);
		for (int pos = 0; pos < N; pos += n) {
			l = pos + 0, r = pos + n/2, m = 0;
			while (m < n/2) {
				auto t = roots[m] * a[r];
				a[r] = a[l] - t;
				a[l] = a[l] + t;
				l++, r++, m++;
			}
		}
	}
	if (f) {
		auto invN = T(1) / T(N);
		for (int i = 0; i < N; i++) a[i] = a[i] * invN;
	}
}
	
template<typename T> vector<T> convolution(vector<T>& a, vector<T>& b) {
	vector<T> l(a.begin(), a.end()), r(b.begin(), b.end());
	int N = l.size()+r.size()-1;
	int n = 1, log_n = 0;
	while (n <= N) n *= 2, log_n++;
	vector<int> rev(n);
	for (int i = 0; i < n; i++) {
		rev[i] = 0;
		for (int j = 0; j < log_n; j++) if (i>>j&1)
			rev[i] |= 1 << (log_n-1-j);
	}
	assert(N <= n);
	l.resize(n);
	r.resize(n);
	fft(l, false, n, rev);
	fft(r, false, n, rev);
	for (int i = 0; i < n; i++) l[i] *= r[i];
	fft(l, true, n, rev);
	l.resize(N);
	return l;
}
	
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, k; cin >> n >> k;
	vector<int> a(n);
	int maxA=0;
	for(int i=0; i<n; i++) {
		cin >> a[i];
		maxA = max(maxA, a[i]);
	}
	
	vector<cmplxd> A(maxA+1, (cmplxd)(0.0));
	for(int i=0; i<n; i++)
		A[a[i]] = A[a[i]]+(cmplxd)(1.0);
	
	vector<cmplxd> B={(cmplxd)1};
	
	while(k>0) {
		if(k%2==1) {
			B = convolution(B,A);
			for(int i=0; i<B.size(); i++) (fabs(B[i].real()) > 0.5 ? B[i]=(cmplxd)1 : B[i]=(cmplxd)0);
			while (!B.empty() && fabsl(B.back().real()) <= 0.5) B.pop_back();
		}
		A = convolution(A,A);
	
		for(int i=0; i<A.size(); i++) (fabs(A[i].real()) > 0.5 ? A[i]=(cmplxd)1 : A[i]=(cmplxd)0);
		while (!A.empty() && fabsl(A.back().real()) <= 0.5) A.pop_back();
		k/=2;
	}
		
	for(int i=0; i<B.size(); i++) {
		if(abs(B[i].real()) > 0.5) {
			cout << i << " ";
		}
	}
	
	cout << "\n";
	
	return 0;
}