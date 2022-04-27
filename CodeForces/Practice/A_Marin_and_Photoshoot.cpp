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

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> pos(0);
    for(int i = 0; i<n; i++){
        if(s[i]=='0') pos.push_back(i);
    }
    int ans = 0;
    // cerr << pos.size()-1 << nl;
    for(int i = 0; i<(int)pos.size() - 1; i++){
        if(pos[i+1] - pos[i] == 2) ans++;
        if(pos[i+1] - pos[i] == 1) ans += 2;
    }
    cout << ans << nl;
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