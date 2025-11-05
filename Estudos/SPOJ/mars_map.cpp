#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 3*1e4;

ll cont[4*MAX]; 
// cont[i] = total de arestas que cobrem intervalo assoc. ao node i
// é preenchido de maneira "lazy" (mais ou menos)
// se intervalo já é coberto, nunca propagamos adiante (queries são feitas na raíz apenas) 
ll length[4*MAX];
// length[i] = comprimento total das arestas no intervalo assoc. ao node i
// calculado de maneira "lazy"
//      se cont[i]>0, então com certeza length[i] = tamanho do intervalo e pronto
//      se não, então simplesmente calculamos com base nos filhos
// para aqueles node não visitados pela recursão, o valor de length não importa (foi contemplado por node acima)


void update(int a, int b, int x, int p=1, int l=0, int r=MAX) {
    if (a <= l and r <= b) {
        cont[p]+=x;
    }
    else if (b < l or r < a) return;
    else {
        int m = (l+r)/2;
        update(a, b, x, 2*p, l, m);
        update(a, b, x, 2*p+1, m+1, r);
    }

    if(cont[p]>0) {
        length[p]=r-l+1;
    }
    else {
        length[p]=0;
        if(l!=r) length[p] = length[2*p]+length[2*p+1];
    }
}

struct Event {
    int x;
    int y1,y2;
    int l;
};

bool comp(const Event& e1, const Event& e2) {
    if(e1.x == e2.x) {
        return e1.l <= e2.l;
    }
    else return e1.x < e2.x;
}

int main() {
    int n; cin >> n;
    vector<Event> v;
    for(int i=0; i<n; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        v.push_back({x1,y1+1,y2,1});
        v.push_back({x2,y1+1,y2,-1});
    }
    sort(v.begin(), v.end(), comp);

    int tot=0, resp=0;
    for(int i=0; i<v.size(); i++) {
        tot = length[1];

        // cout << v[i].x << ": " << v[i].y1 << " - "  << v[i].y2;
        // cout << " >>> " << tot << "\n";

        if(i>0) resp += tot*(v[i].x-v[i-1].x);

        update(v[i].y1, v[i].y2, v[i].l);
    }

    cout << resp << "\n";

}