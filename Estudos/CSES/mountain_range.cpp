#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int h[n];
    for(int i=0; i<n; i++) cin >> h[i];

    stack<int> s1;
    int left[n];

    left[0]=0;
    s1.push(0);
    for(int i=1; i<n; i++) {
        left[i] = 0;
        while(!s1.empty() && h[s1.top()]<h[i]) {
            int i0 = s1.top(); s1.pop();
            left[i] = max(left[i]+1, left[i0]+1);
        }
        if(!s1.empty() && h[s1.top()]==h[i]) {
            if(left[i]>left[s1.top()]) {
                s1.pop(); s1.push(i);
            }
        }
        else s1.push(i);
    }

    stack<int> s2;
    int right[n];

    right[n-1]=0;
    s2.push(n-1);
    for(int i=n-2; i>=0; i--) {
        right[i] = 0;
        while(!s2.empty() && h[s2.top()]<h[i]) {
            int i0 = s2.top(); s2.pop();
            right[i] = max(right[i]+1, right[i0]+1);
        }
        if(!s2.empty() && h[s2.top()]==h[i]) {
            if(right[i]>right[s2.top()]) {
                s2.pop(); s2.push(i);
            }
        }
        else s2.push(i);
    }
    
    // for(int i=0; i<n; i++) cout << left[i] << " ";
    // cout << "\n";

    // for(int i=0; i<n; i++) cout << right[i] << " ";
    // cout << "\n";

    int resp=0;
    for(int i=0; i<n; i++) resp = max(resp, max(left[i]+1, right[i]+1));
    cout << resp << "\n";
    
    return 0;
}