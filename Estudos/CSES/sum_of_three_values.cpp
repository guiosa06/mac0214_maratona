#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, X; cin >> n >> X;
    vector<pair<int,int>> v;
    for(int i=0; i<n; i++){
        int a; cin >> a;
        v.push_back({a,i+1});
    }
    sort(v.begin(), v.end());

    for(int i=0; i<n-2; i++) {
        int x = X - v[i].first;
        int l=i+1, r=n-1;
        while(l!=r){
            int sum = v[l].first+v[r].first;
            if(sum>x) r--;
            else if(sum<x) l++;
            else{
                cout << v[i].second << " " << v[l].second << " " << v[r].second << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}