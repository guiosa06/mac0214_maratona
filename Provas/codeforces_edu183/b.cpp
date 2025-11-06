#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n,k; cin >> n >> k;
        string s; cin >> s;
        vector<char> resp(n);
        int top=0, botton=n-1, unk=0;
        for(int i=0; i<k; i++) {
            if(s[i]=='0') {
                resp[top]='-';
                top++;
            }
            else if(s[i]=='1') {
                resp[botton]='-';
                botton--;
            }
            else unk++;
        }

        char aux;
        if(k==n)aux='-';
        else aux='?';
        while(unk>0 && botton>=top) {
            resp[botton--]=resp[top++]=aux;
            unk--;
        }
        while(botton>=top) {
            resp[botton--]=resp[top++]='+';
        }

        for(auto c:resp) cout << c;
        cout << "\n";
    }
    
    return 0;
}