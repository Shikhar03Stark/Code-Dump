// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

ll se(int n){
    if(n%2==1){
        ll k = (n-1)/2;
        return (k*(k+1));
    }
    else{
        ll k = n/2;
        return (k*(k+1));
    }
}

ll so(int n){
    if(n%2==1){
        ll k = (n+1)/2;
        return k*k;
    }
    else{
        ll k = n/2;
        return k*k;
    }
}

void solve(){
    
    ll l,r;
    cin >> l >> r;
    ll sume = se(r) - se(l-1);
    ll sumo = so(r) - so(l-1);
    cerr << sume << " " << sumo << nl;
    cout << sume - sumo << nl;
    return;
}

int main(){
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}