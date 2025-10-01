#include <bits/stdc++.h>
using namespace std;

int f[26], freq[26];

int main() {

    string s; cin >> s;
    vector<char> letters;
    int n=s.size(), maxfreq=0;

    for(int i=0; i<n; i++) {
        if(f[(int)(s[i]-'A')]==0) letters.push_back(s[i]);
        maxfreq = max(maxfreq, ++f[(int)(s[i]-'A')]);
    }

    for(int i=0; i<26; i++) freq[i]=f[i];

    if(maxfreq > (n+1)/2) {
        cout << -1 << "\n";
        return 0;
    }

    sort(letters.begin(), letters.end());
    vector<char> reorder(n);
    int idx=0;

    for(int i=0; i<letters.size(); i++) {
        int j=i+1;
        while(freq[letters[i]-'A']!=0) {
            if(reorder[idx-1]!=letters[i]) {
                reorder[idx]=letters[i];
                freq[letters[i]-'A']--;
                idx++;
            }

            while(j<letters.size() && freq[letters[j]-'A']==0) j++;
            if(j==letters.size() && idx<n) {
                idx--;
                vector<char> tail;
                for(int aux=0; aux<f[letters[i]-'A']-1; aux++) {
                    while(reorder[idx]==letters[i]) idx--;
                    tail.push_back(reorder[idx--]);
                }
                idx++;
                sort(tail.begin(), tail.end());

                int k=0;
                while(idx<n) {
                    reorder[idx++]=letters[i];
                    if(idx<n) reorder[idx++]=tail[k++];
                }
                break;
            }
            else if(idx<n) {
                reorder[idx]=letters[j];
                freq[letters[j]-'A']--;
                idx++;
            }
        }
    }

    for(int i=0; i<n; i++) cout << reorder[i];

}