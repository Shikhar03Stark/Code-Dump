#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

ll powmod(ll a, ll n, ll mod = 1e9+7){
    if(n == 1) return a;
    if(n == 0) return 1;
    ll ans = powmod(a, n/2, mod);
    ans = ((ans%mod)*(ans%mod)%mod);
    if(n%2==0){
        return ans;
    }
    else{
        return ((a%mod)*(ans%mod))%mod;
    }
}


int solve(){
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    int exp = 0;
    ll mod = 1e9+7;
    while(k){
        if(k%2==1){
            ll a = powmod(n, exp);
            ans = ((ans%mod)+(a%mod))%mod;
        }
        k = (k>>1);
        exp++;
    }
    cout << ans << endl;
    return 0;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}