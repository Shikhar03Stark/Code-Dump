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
    // int n = s.size();
    map<int, int> h;
    int sum = 0;
    h[0] = 1;
    for(int i = 0; i<n; i++){
        sum += s[i] - '0';
        h[sum-i-1]++;
    }
    ll ans = 0;
    for(auto& e: h){
        // cerr << e.first << " " << e.second << nl;
        ll x = e.second;
        ans += max(0LL, (x*(x-1))/2);
    }
    // cerr << nl;
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