#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define int long long

struct pt {
    int x,y, id;
    pt(int x_=0, int y_=0) : x(x_), y(y_) {}
    bool operator < (const pt p) const {
        if(x!=p.x) return x<p.x;
        return y<p.y;
    }
    bool operator == (const pt p) const {
        return x==p.x && y==p.y;
    }
    pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
    pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
    pt operator * (const int c) const { return pt(x*c, y*c); }
    pt operator * (const pt p) const { return x*(ll)p.x + y*(ll)p.y; }
    ll operator ^ (const pt p) const { return x*(ll)p.y - y*(ll)p.x; }
    friend istream& operator >> (istream& in, pt& p) {
        return in >> p.x >> p.y;
    }
};

ll sarea2(pt p, pt q, pt r) {
    return (q-p)^(r-q);
}

bool ccw(pt p, pt q, pt r) {
    return sarea2(p,q,r) >= 0;
}

bool flag=0;

vector<pt> convex_hull(vector<pt> v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    if(v.size() <= 1) return v;
    vector<pt> l,u;
    for(int i=0; i<v.size(); i++) {
        while(l.size()>1 && !ccw(l.end()[-2], l.end()[-1], v[i])) {
            l.pop_back();
        }
        if(u.size()>1 && sarea2(l.end()[-2], l.end()[-1], v[i]) != 0) flag=1;
        l.push_back(v[i]);
    }
    for(int i=v.size()-1; i>=0; i--) {
        while(u.size()>1 && !ccw(u.end()[-2], u.end()[-1], v[i])) {
            u.pop_back();
        }
        if(u.size()>1 && sarea2(u.end()[-2], u.end()[-1], v[i]) != 0) flag=1;
        u.push_back(v[i]);
    }
    l.pop_back(); u.pop_back();
    for(pt i:u) l.push_back(i);
    return l;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    vector<pt> P;
    for(int i=0; i<n; i++) {
        pt aux; cin >> aux;
        aux.id=i+1;
        P.push_back(aux);
    }

    vector<pt> conv = convex_hull(P);
    vector<int> resp;
    for(int i=0; i<conv.size(); i++) {
        resp.push_back(conv[i].id);
    }
    sort(resp.begin(), resp.end());
    if(!flag) {
        for(int i=1; i<=n; i++) cout << i << " ";
    }
    else {
        for(int i=0; i<resp.size(); i++) cout << resp[i] << " ";
    }
    cout << "\n";
}