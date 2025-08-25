#include <bits/stdc++.h>
using namespace std;
const int MAXF=1e6+5;

int s[MAXF], freq[MAXF], indeg[MAXF];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for(int i=1; i<MAXF; i++) {
        string aux = to_string(i);
        for(int j=0; j<aux.size(); j++) {
             s[i] += (aux[j]-'0');
        }
        s[i] = i-s[i];
        //cout << i << " " << s[i] << "\n";
        indeg[s[i]]++;
    }

    queue<int> q;
    for(int i=1; i<MAXF; i++) {
         if(indeg[i]==0) q.push(i);
    }

    int n, k; cin >> n >> k;
    for(int i=0; i<n; i++) {
        int aux; cin >> aux;
        freq[aux]++;
    }

    while(!q.empty()) {
        int at=q.front(); q.pop();
        indeg[s[at]]--;
        freq[s[at]] += freq[at]; 

        if(indeg[s[at]]==0) q.push(s[at]);
    }

    int sum=0;
    for(int i=MAXF-1; i>=0; i--) {
        // cout << i << " " << freq[i] << "\n";
        sum+=freq[i]; 
        if(sum>=k) {
            cout << i-s[i] << "\n";
            return 0;
        }
    }

    cout << 0 << "\n";

    return 0;
}