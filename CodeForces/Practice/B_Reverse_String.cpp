// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void pre(){
    
    return;
}

bool match(string &s, string & t, int i, int j, bool go_right){
    int ns = s.size(), nt = t.size();
    if(j>=nt) return true;
    if(i<0 || i>= ns) return false;
    if(s[i] != t[j]) return false;
    if(go_right)
        return match(s, t, i+1, j+1, go_right) || match(s, t, i-1, j+1, !go_right);
    else
        return match(s, t, i-1, j+1, go_right);
}

void solve(){
    string s, t;
    cin >> s >> t;
    for(int i = 0; i<s.size(); i++){
        if(match(s, t, i, 0, true)){
            cout << "YES" << nl;
            return;
        }
    }
    cout << "NO" << nl;
    return;
}

int main(){
    FASTIO
    pre();
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}