// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

const int N = 1e7;

vector<int> p(N+1, true);
vector<int> prime;
int psz;

void pre(){
    // p[0] = p[1] = false;
    // for(ll i = 2; i*i<=N; i++){
    //     if(p[i]){
    //         for(ll j = i*i; j<=N; j+=i){
    //             p[j] = false;
    //         }
    //     }
    // }
    // for(int i = 2; i<=N; i++){
    //     if(p[i]) prime.push_back(i);
    // }
    // psz = prime.size();
    return;
}

vector<ll> pf(ll n){
    vector<ll> ans;
    for(ll i = 2; i*i<=n; i++){
        if(n%i==0){
            ans.push_back(i);
            while(n%i==0){
                n /= i;
            }
        }
    }
    if(n>1) ans.push_back(n);
    return ans;
}

ll pos(ll p, ll q, ll d){
    ll x = p;
    while(x%q==0){
        x /= d;
    }
    return x;
}

void solve(){
    ll p, q;
    cin >> p >> q;
    if(p%q){
        cout << p << nl;
    }
    else{
        auto arr = pf(q);
        ll ans = 1;
        for(auto& e: arr){
            ans = max(ans, pos(p, q, e));
        }
        cout << ans << nl;
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