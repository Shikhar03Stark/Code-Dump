// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    ll n;
    cin >> n;
    bool found = false;
    for(ll i = 2; i<n & !found; i++){
        if(__gcd(i, n-i-1) == 1){
            cout << i << " " << n-i-1 << " " <<  1 << nl;
            return;
        }
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