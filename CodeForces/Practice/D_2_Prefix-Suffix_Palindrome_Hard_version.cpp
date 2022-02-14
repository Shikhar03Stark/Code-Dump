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

const ll pr = 31;
const ll mod = 1e9+7;

ll mak_hash(const string& s){
    ll h = 0;
    ll prime = 1;
    for(const auto& c: s){
        h = (h + (c - 'a' + 1)*prime) % mod;
        prime = (prime*pr) % mod;
    }
    return h;
}

void solve(){
    string s;
    cin >> s;
    cout << mak_hash(s) << nl;
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