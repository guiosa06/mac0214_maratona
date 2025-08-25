#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;

    int finish=-1, currd=-1, waiting=-1;

    for(int i=0; i<n; i++) {
        int t,d; cin >> t >> d;
        if(finish<t && waiting!=-1) {
            finish += 10; currd = waiting;
            waiting = -1;
        }

        if(finish<t) {
            finish = t+10; currd = d;
        }
        else {
            if(currd == d) finish = t+10;
            else waiting = d;
        }
    }
    if(waiting!=-1) {
            finish += 10; currd = waiting;
            waiting = -1;
        }

    cout << finish << "\n";
    return 0;
}