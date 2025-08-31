#include<bits/stdc++.h>
using namespace std;

int main() {
	int a,b,c; cin >> a >> b >> c;

	if ((b-a)%c==0) cout << "S";
	else cout << "N";
}
