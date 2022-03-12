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

ll f(ll x, ll a){
    return (x - (x/a)*(a-1));
}

void solve(){
    ll l, r, a;
    cin >> l >> r >> a;
    ll q = (r+1)/a;
    ll k = q*a-1;
    if(k>=l && k<=r)
        cout << f(k, a) << nl;
    else{
        cout << f(r, a) << nl;
    }
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