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
    ll n;
    cin >> n;
    vector<ll> arr(n);
    ll tx = 0;
    for(auto& e: arr){
        cin >> e;
        tx ^= e;
    }
    ll ans = tx;
    vector<ll> dp(n, -1);
    for(int i = 0; i<n; i++){
        if(i){
            if(arr[i] > dp[i-1]^arr[i]){
                dp[i] = arr[i];
            }
            else{
                dp[i] = arr[i]^dp[i-1];
            }
        }
        else{
            dp[i] = arr[i];
        }
        // ans = max(tx, dp[i]);
    }
    for(int i = 0; i<n; i++){
        ans = max(ans, dp[i]);
    }
    
    cout << ans << nl;
    return;
}

int main(){
    FASTIO
    pre();
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}