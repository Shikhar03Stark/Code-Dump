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
    vector<ll> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    ll ans = LLONG_MAX;
    for(int  p = 0; p<n; p++){
        vector<ll> b(n, 0);
        ll cnt = 0;
        for(int i = p+1; i<n; i++){
            ll x = b[i-1]/arr[i] + 1LL;
            cnt += x;
            b[i] = x*arr[i];
        }
        for(int i = p-1; i>=0; i--){
            ll x = b[i+1]/arr[i] + 1LL;
            cnt += x;
            b[i] = x*arr[i];
        }

        ans = min(ans, cnt);
    }
    cout << ans << nl;
    return;
}

int main(){
    FASTIO
    pre();
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}