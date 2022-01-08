// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    ll n;
    cin >> n;
    ll x = sqrt(n), y = cbrt(n);
    ll ans = x;
    for(ll i = y; i>=2; i--){
        double a = sqrt(i);
        if(ceil(a) != floor(a)){
            ans++;
        }
    }
    cout << ans << nl;
    return 0;
}

int main(){
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}