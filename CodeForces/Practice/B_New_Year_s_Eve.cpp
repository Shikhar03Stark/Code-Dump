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
    if(k==1){
        cout << n << nl;
        return;
    }
    ll p = 0;
    while((1LL<<p) <= n){
        p++;
    }
    p--;
    ll ans = 0;
    while(p>=0 && k>0){
        ans += (1LL<<p);
        p--;
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