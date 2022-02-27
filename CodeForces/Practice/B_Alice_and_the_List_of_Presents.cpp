// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

const int mod = 1e9+7;

ll modpow(ll b, ll a){
    if(a == 0) return 1LL;
    if(a == 1) return b;
    ll h = modpow(b, a/2);
    h = (h*h) % mod;
    if(a%2){
        return (b*h)%mod;
    }
    else{
        return h;
    }
}

ll modinv(ll n){
    return modpow(n, mod-2);
}

void pre(){
    
    return;
}

void solve(){
    ll n, m;
    cin >> n >> m;
    ll ans = modpow(2, m);
    ans = (mod + ans - 1) % mod;
    ans = modpow(ans, n);
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