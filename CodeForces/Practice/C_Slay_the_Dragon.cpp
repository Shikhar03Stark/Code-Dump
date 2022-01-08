// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    ll n;
    cin >> n;
    vector<ll> arr(n);
    ll sum = 0;
    for(auto &e: arr){
        cin >> e;
        sum += e;
    }
    ll m;
    cin >> m;
    vector<pair<ll,ll>> drr(m);
    for(auto& p: drr){
        cin >> p.first >> p.second;
    }
    sort(arr.begin(), arr.end());
    for(auto& d: drr){
        int idx = lower_bound(arr.begin(), arr.end(), d.first) - arr.begin();
        ll ans = 2e18;
        if(idx>0) ans = min(ans, d.first-arr[idx-1] + max(0LL, d.second-sum+arr[idx-1]));
        if(idx<n) ans = min(ans, max(0LL, d.second-sum+arr[idx]));

        cout << ans <<nl;

    }
    return 0;
}

int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}