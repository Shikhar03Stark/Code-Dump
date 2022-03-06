// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

vector<ll> fact;
int sz;
void pre(){
    const ll N = 1e12;
    ll f = 1;
    ll i = 1;
    while(f*i <= N){
        // cerr << f*i << nl;
        fact.push_back(f = f*i);
        i++;
    }
    sz = fact.size();
    return;
}

int setbits(ll n){
    ll c = 0;
    // cerr << "* ";
    for(ll i = 0; i<64; i++){
        if((n&(1LL<<i)) > 0){c++;}
    }
    return c;
}

void ans(int i, ll n, int &r, int c){
    if(n<0) return;
    if(i<0) return;
    r = min(r, setbits(n)+c);
    ans(i-1, n-fact[i], r, c+1);
    ans(i-1, n, r, c);
}

void solve(){
    // cerr << sz << nl;
    ll n;
    cin >> n;
    int r= setbits(n);
    // set<ll> done;
    ans(sz-1, n, r, 0);
    // cerr << nl;
    cout << r << nl;
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