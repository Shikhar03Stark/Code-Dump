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
    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    sort(arr.begin(), arr.end());
    ll ans = 0;
    for(int i = 0; i<n; i++){
        auto lb = lower_bound(arr.begin(), arr.begin()+i, l-arr[i]) - arr.begin();
        auto ub = upper_bound(arr.begin(), arr.begin()+i, r-arr[i]) - arr.begin();
        ans += ub-lb;
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