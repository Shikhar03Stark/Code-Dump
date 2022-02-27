// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void pre(){
    cerr <<".\t";
    for(int i = 8; i<=18; i++){
        cerr << i << "\t";
    }
    cerr << nl;
    for(int i = 4; i<=7; i++){
        cerr << i << '\t';
        for(int j = 8;j<=18; j++){
            cerr << (i^j) << '\t';
        }
        cerr << nl;
    }
    return;
}

void solve(){
    ll n, m;
    cin >> n >> m;
    if(n==0) {
        cout << m+1 << nl;
        return;
    }
    ll lg = 0;
    ll t = n;
    while(t){
        lg++;
        t = (t>>1);
    }
    lg = pow(2, lg);
    ll q = n/lg;
    ll rm = m%lg;
    ll ans = q*lg;
    for(ll j = q*lg; j<=m; j++){

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