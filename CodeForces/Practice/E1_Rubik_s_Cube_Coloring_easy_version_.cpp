// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

const ll mod = 1e9+7;

ll modpow(ll b, ll exp){
    if(exp==0){
        return 1LL;
    }
    if(exp==1){
        return b;
    }
    ll half = modpow(b, exp/2);
    ll mult = ((half%mod)*(half%mod))%mod;
    if((exp&1==1)){
        return ((b%mod)*(mult%mod))%mod;
    }
    return mult;
}

ll modinv(ll n){
    return modpow(n, mod-2);
}

void solve(){
    int k;
    cin >> k;
    if(k==1){
        cout << 6 << nl;
        return;
    }
    else{
        ll nodes = pow(2, k);
        nodes = nodes-2;
        ll ans = modpow(4, nodes);
        cout << (ans*6)%mod << nl;
        return;
    }
    return;
}

int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}