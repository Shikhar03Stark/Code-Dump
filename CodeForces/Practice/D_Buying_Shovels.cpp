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
    ll n, k;
    cin >> n >> k;
    ll ans = n;
    for(ll i = 1; i*i <= n; i++){
        if(n%i==0){
            ll cnt = min(i, n/i);
            ll p = n/cnt;
            if(p<=k){
                ans = min(ans, cnt);
            }
            else if(cnt <= k){
                ans = min(ans, p);
            }
        }
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