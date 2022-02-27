// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

const int mod = 1e9+7;
vector<ll> factorial(1001);
vector<ll> finv(1001);

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
    factorial[0] = factorial[1] = 1;
    for(ll i = 1; i<=1000; i++){
        factorial[i] = (factorial[i-1] * i) % mod;
    }
    for(ll i = 0; i<=1000; i++){
        finv[i] = modinv(factorial[i]);
    }
    return;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    sort(arr.begin(), arr.end());
    map<int, int> tot, have;
    for(int i = 0; i<n; i++){
        tot[arr[i]]++;
    }
    ll sum = 0;
    for(int i = n-1; i>=n-k; i--){
        sum += arr[i];
        have[arr[i]]++;
    }

    ll ans = 1;
    for(auto& p: have){
        ll t = tot[p.first], q = p.second;
        ll val = (factorial[t] * finv[t-q]) % mod;
        val = (val * finv[q]) % mod;
        ans = (ans * val) % mod;
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