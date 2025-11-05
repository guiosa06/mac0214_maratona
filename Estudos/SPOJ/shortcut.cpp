#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int MAXN = 250000;
const int INF = 1e9;


struct Break {
    int x,y;
    int i;
};

bool comp1(const Break& p1, const Break& p2) {
    return p1.x < p2.x;
}
bool comp2(const Break& p1, const Break& p2) {
    return p1.y < p2.y;
}

pii lastX[2*MAXN+10], lastY[2*MAXN+10];


int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;

        vector<Break> v;
        v.push_back({MAXN,MAXN,0});
        int x=0,y=0;
        for(int i=0; i<n; i++) {
            if(s[i]=='N') y++;
            else if(s[i]=='E') x++;
            else if(s[i]=='S') y--;
            else x--;
            v.push_back({x+MAXN,y+MAXN,i+1});
        }

        int resp = INF, b, e; char d;

        sort(v.begin(), v.end(), comp1);
        for(int i=0; i<=2*MAXN; i++) lastX[i]={INF,-1};
        for(int i=0; i<v.size(); i++) {
            int last = lastX[v[i].y].first, at = v[i].x;
            int lasti = lastX[v[i].y].second, ati = v[i].i;
            char dtmp = 'E';
            if(lasti>ati) {
                swap(lasti,ati);
                dtmp = 'W';
            }

            if(last!=INF && (ati-lasti)!=1) {
                bool CHANGE=0;
                if(resp > (at-last)) CHANGE=1;
                else if(resp == (at-last)) {
                    if(lasti<b) CHANGE=1;
                    else if(lasti == b) {
                        if(ati > e) CHANGE=1;
                    }
                }

                if(CHANGE) {
                    resp = (at-last);
                    b = lasti;
                    e = ati;
                    d = dtmp;
                } 
            } 
            lastX[v[i].y]={v[i].x, v[i].i};
        }

        sort(v.begin(), v.end(), comp2);
        for(int i=0; i<=2*MAXN; i++) lastY[i]={INF,-1};
        for(int i=0; i<v.size(); i++) {
            int last = lastY[v[i].x].first, at = v[i].y;
            int lasti = lastY[v[i].x].second, ati = v[i].i;
            char dtmp = 'N';
            if(lasti>ati) {
                swap(lasti,ati);
                dtmp = 'S';
            }

            if(last!=INF && abs(ati-lasti)!=1) {
                bool CHANGE=0;
                if(resp > (at-last)) CHANGE=1;
                else if(resp == (at-last)) {
                    if(lasti<b) CHANGE=1;
                    else if(lasti == b) {
                        if(ati > e) CHANGE=1;
                    }
                }

                if(CHANGE) {
                    resp = (at-last);
                    b = lasti;
                    e = ati;
                    d = dtmp;
                } 
            }
            lastY[v[i].x]={v[i].y, v[i].i};
        }

        cout << resp << " " << b << " " << e << " " << d << "\n";
    }
    return 0;
}