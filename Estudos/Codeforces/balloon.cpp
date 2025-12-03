#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5;
const int INF = 1e9;
const pair<int,int> no_lazy={-2,-2};
const int id=-1;

// GEOMTRIA /////////////////////////////////////////////////////
// brunomaletta
struct pt { // ponto
    int x, y;
    pt(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
    bool operator < (const pt p) const {
        if (x != p.x) return x < p.x;
        return y < p.y;
    }
    bool operator == (const pt p) const {
        return x == p.x and y == p.y;
    }
    pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
    pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
    pt operator * (const int c) const { return pt(x*c, y*c); }
    ll operator * (const pt p) const { return x*(ll)p.x + y*(ll)p.y; }
    ll operator ^ (const pt p) const { return x*(ll)p.y - y*(ll)p.x; }
    friend istream& operator >> (istream& in, pt& p) {
        return in >> p.x >> p.y;
    }
};
struct line { // reta
    pt p, q; int idx;
};
ll sarea2(pt p, pt q, pt r) { // 2 * area com sinal
    return (q-p)^(r-q);
}
bool ccw(pt p, pt q, pt r) { // se p, q, r sao ccw
    return sarea2(p, q, r) > 0;
}

vector<line> v;

struct cmp_sweepline {
	bool operator () (const int ia, const int ib) const {
		// assume que os segmentos tem p < q
        line a = v[ia], b = v[ib];
		if (a.p == b.p) return ccw(a.p, a.q, b.q);
		if (a.p.x != a.q.x and (b.p.x == b.q.x or a.p.x < b.p.x))
			return ccw(a.p, a.q, b.p);
		return ccw(a.p, b.q, b.p);
	}
};

// EVENTOS da LINE SWEEP //////////////////////////////////////
struct Event {
    int x;
    int type;
    // 1 se é o começo de um segmento
    // 3 se é o fim de um segmento
    // 2 se é uma query
    int idx;
};
bool cmp_events(const Event& e1, const Event& e2) {
    if(e1.x==e2.x) {
        return e1.type<e2.type;
    }
    return e1.x<e2.x;
}


// SET para LINE SWEEP /////////////////////////////////////////
set<int, cmp_sweepline> curr_lines;
int next_in_set(int i) {
    auto it = curr_lines.find(i);
    it++;
    if(it==curr_lines.end()) return -1;
    else return *it;
}

// DAG para DP com os destinos dos balões //////////////////////
vector<int> adj[MAXN];
vector<int> pai(MAXN,-1), indeg(MAXN,0);
pair<int,int> destino[MAXN];   // ponto em que balão acaba ao começar no segmento i
    
void calcula_destino(int n) {
    queue<int> q;
    for(int i=0; i<n; i++) {
        if(indeg[i]==0) q.push(i);
    }

    while(!q.empty()) {
        int at=q.front();

        if(pai[at]==-1) {
            if(v[at].p.y == v[at].q.y) destino[at] = {-1, v[at].p.y};
            else if(v[at].p.y < v[at].q.y) destino[at] = {v[at].q.x, INF};
            else destino[at] = {v[at].p.x, INF};
        }
        else {
            destino[at] = destino[pai[at]];
            if(destino[at].first==-1) {
                if(v[at].p.y < v[at].q.y) destino[at].first = v[at].q.x;
                else destino[at].first = v[at].p.x;
            }
        }

        //cout << at << " " << destino[at].first << " "<< destino[at].second << "\n";

        q.pop();
        for(auto to:adj[at]) {
            indeg[to]--;
            if(indeg[to]==0) q.push(to);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // ENTRADA
    int n, c; cin >> n >> c;
    vector<Event> events;
    for(int i=0; i<n; i++) {
        pt a,b; cin >> a >> b;
        if(b<a) swap(a,b);

        v.push_back({a,b,i});
        events.push_back({a.x,1,i});
        events.push_back({b.x,3,i});
    }
    
    int queries[c];
    for(int i=0; i<c; i++) {
        cin >> queries[i];
        events.push_back({queries[i],2,i});
    }

    sort(events.begin(), events.end(), cmp_events);

    // PROCESSAMENTO DOS EVENTOS
    int seg_acima[c];           // índice do segmento logo acima de balão i
    for(auto e:events) {
        if(e.type==1) {
            curr_lines.insert(e.idx);
            
            if(v[e.idx].p.y > v[e.idx].q.y) {
                int above = next_in_set(e.idx);
                if(above!=-1) {
                    pai[e.idx] = above;
                    adj[above].push_back(e.idx);
                    indeg[e.idx]++;
                }
            }
        }
        else if(e.type==3) {            
            if(v[e.idx].p.y < v[e.idx].q.y) {
                int above = next_in_set(e.idx);
                if(above!=-1) {
                    pai[e.idx] = above;
                    adj[above].push_back(e.idx);
                    indeg[e.idx]++;
                }
            }

            curr_lines.erase(e.idx);
        }
        else {
            if(curr_lines.empty()) seg_acima[e.idx] = -1;
            else seg_acima[e.idx] = *curr_lines.begin();
        }
    }

    // for(int i=0; i<n; i++) {
    //     cout << i << ": ";
    //     for(auto to:adj[i]) cout << to << " ";
    //     cout << "\n";
    // }

    // CÁLCULO DA DP E DAS RESPOSTAS
    calcula_destino(n);
    for(int i=0; i<c; i++) {
        if(seg_acima[i]==-1) cout << queries[i] << "\n";
        else {
            pair<int,int> resp = destino[seg_acima[i]];
            if(resp.first==-1) resp.first = queries[i];

            cout << resp.first;
            if(resp.second!=INF) cout << " " << resp.second;
            cout << "\n";
        }
    }


    
}