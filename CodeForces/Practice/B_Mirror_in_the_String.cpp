// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

bool possible(string &s, int k){
    bool pos = true;
    int i = k-1;
    while(pos && i>=0){
        pos &= (s[k]<=s[i]);
        i -= 2;
    }
    return pos;
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n==1){
        cout << s[0] << s[0] << nl;
        return;
    }
    vector<bool> f(n, false);
    f[0] = (s[0]>s[1]);
    for(int i = 1; i<n-1; i++){
        if(f[i-1] && s[i]>s[i+1]) f[i] = true;
        if(s[i]==s[i+1]) f[i] = f[i-1];
    }
    int k = 0;
    for(;k<n; k++){
        if(!f[k]){
            break;
        }
    }
    cout << s.substr(0,k+1);
    reverse(s.begin(), s.begin()+k+1);
    cout << s.substr(0,k+1) << nl;

    return;
}

int main(){
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}