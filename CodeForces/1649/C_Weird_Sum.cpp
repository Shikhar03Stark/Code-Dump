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
    int n, m;
    cin >> n >> m;
    map<ll, vector<ll>> X, Y;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int c;
            cin >> c;
            X[c].push_back(j);
            Y[c].push_back(i);
        }
    }
    ll ans = 0;
    for(auto& e: X){
        sort(e.second.begin(), e.second.end());
        int sz = e.second.size();
        vector<ll> suf(sz+1,0);
        for(int i = sz-1; i>=0; i--){
            suf[i] = suf[i+1] + e.second[i];
        }

        for(int i = 0; i<sz-1; i++){
            ans += suf[i+1] - e.second[i]*(sz-i-1);
        }
    }

    for(auto& e: Y){
        sort(e.second.begin(), e.second.end());
        int sz = e.second.size();
        vector<ll> suf(sz+1,0);
        for(int i = sz-1; i>=0; i--){
            suf[i] = suf[i+1] + e.second[i];
        }

        for(int i = 0; i<sz-1; i++){
            ans += suf[i+1] - e.second[i]*(sz-i-1);
        }
    }

    cout << ans << nl;

    return;
}

int main(){
    FASTIO
    pre();
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}