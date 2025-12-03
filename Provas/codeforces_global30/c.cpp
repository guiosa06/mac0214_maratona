#include <bits/stdc++.h>
using namespace std;
    
struct Monster {
    int b,c;
};
bool comp(const Monster& m1, const Monster& m2) {
    if(m1.b==m2.b) return (m1.c > m2.c);
    return (m1.b < m2.b);
}
    
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while(t--) {
        int n,m; cin >> n >> m;
        priority_queue<int, vector<int>, greater<int>> a;
        priority_queue<int, vector<int>, greater<int>> resto;
        vector<int> b(m);
        vector<Monster> v;
        vector<int> puxa_vida;
    
        for(int i=0; i<n; i++) {
            int aux; cin >> aux;
            a.push(aux);
        }
        for(int i=0; i<m; i++) cin >> b[i];
        for(int i=0; i<m; i++) {
            int aux; cin >> aux;
            if(!aux) puxa_vida.push_back(b[i]);
            else v.push_back({b[i],aux});
        }
    
        sort(v.begin(), v.end(), comp);
        sort(puxa_vida.begin(), puxa_vida.end());
        int idx=0, ans=0;
        while(idx<v.size() && !a.empty()) {
            int sword = a.top();
            a.pop();
    
            if(v[idx].b > sword){
                resto.push(sword);
                continue;
            } 
    
            a.push(max(sword, v[idx].c));
            ans++;
            idx++;
        }
    
        while(!a.empty()) {
            resto.push(a.top());
            a.pop();
        }
    
        idx=0;
        while(idx<puxa_vida.size() && !resto.empty()) {
            int sword = resto.top();
            resto.pop();
    
            if(puxa_vida[idx] > sword){
                continue;
            } 
    
            ans++;
            idx++;
        }
    
        cout << ans << "\n";
    }
}