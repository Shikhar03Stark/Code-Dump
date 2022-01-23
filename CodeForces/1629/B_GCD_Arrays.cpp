// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    ll l, r, k;
    cin >> l >> r >> k;
    if(l==r && l!=1){
        cout << "YES" << nl;
        return;
    }
    if(l==r && l==1){
        cout << "NO" << nl;
        return;
    }
    auto numodds = [](int n){
        return (n+1)/2;
    };

    ll odds = numodds(r) - numodds(l-1);
    if(odds <= k){
        cout << "YES" << nl;
    }
    else{
        cout << "NO" << nl;
    }

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