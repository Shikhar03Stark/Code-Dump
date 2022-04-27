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
    ll n, x;
    cin >> n >> x;
    vector<ll> cost(n);
    for(auto& e: cost){
        cin >> e;
    }
    sort(cost.begin(), cost.end());
    vector<ll> pre(n+1);
    for(int i = 0; i<n; i++){
        pre[i+1] = pre[i] + cost[i];
    }
    ll k = n;
    ll H = 0;
    ll ans = 0;
    while(k>0){
        ll delta = x - pre[k] - k*(H);
        while(delta < 0 && k>0){
            k--;
            delta = x - pre[k] - k*(H);
        }
        if(k == 0) break;
        ll n = delta/k;
        H += (1+n);

        ans += k*(1+n);
    }
    cout << ans << nl;
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