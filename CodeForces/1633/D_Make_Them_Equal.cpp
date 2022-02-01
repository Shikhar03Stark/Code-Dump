// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

ll knapsack(vector<int> &ops, vector<int> &cost, int idx, ll k, map<pair<int,ll>, ll> &dp){
    if(idx<0){
        return 0;
    }
    if(dp.count({idx, k}) > 0){
        return dp[{idx,k}];
    }

    if(ops[idx] <= k){
        return dp[{idx,k}] = max(cost[idx]+knapsack(ops, cost, idx-1, k-ops[idx], dp), knapsack(ops, cost, idx-1, k, dp));
    }
    else{
        return dp[{idx,k}] = knapsack(ops, cost, idx-1, k, dp);
    }

}

const int N = 1e3+5;

vector<int> cnt(N, INT_MAX);

void solve(){
    ll n, k;
    cin >> n >> k;
    vector<int> b(n), c(n);
    for(auto& e: b){
        cin >> e;
    }
    for(auto& e: c){
        cin >> e;
    }
    vector<int> ops(n,0);
    for(int i = 0; i<n; i++){
        ops[i] = cnt[b[i]];
        //cerr << b[i] << " ";
            // while(a[i]<b[i]){
            //         ll x = ceil((0.0+a[i])/(b[i]-a[i]));
            //         a[i] += a[i]/x;
            //         //cerr << a[i] << ":" << x << " ";
            //         ops[i]++;
            //     }
        //cerr << nl;
        // while(a[i] < b[i] && (a[i]<<1LL)<=b[i]){
        //     a[i] = (a[i]<<1LL);
        //     ops[i]++;
        // }
        // if(a[i]!=b[i]){
        //     // ll d = b[i]-a[i];
        //     // while(d>0){
        //     //     d = (d>>1);
        //     //     ops[i]++;
        //     // }
            
        // }
    }

    // for(auto& e: ops){
    //     cerr << e << " ";
    // }
    // cerr << nl;
    // for(int i = 0; i<n; i++){
    //     cerr << b[i]-a[i] << " ";
    // }
    // cerr << nl;
    int tot = 0;
    for(int i = 0; i<n; i++){
        tot += ops[i];
    }
    vector<vector<int>> dp(2, vector<int>(1+min(tot,(int)k), 0));
    int ans = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<=min(tot,(int)k); j++){
            if(i){
                if(ops[i] <= j){
                    dp[i%2][j] = max(c[i] + dp[(i+1)%2][j-ops[i]], dp[(i+1)%2][j]);
                }
                else{
                    dp[i%2][j] = dp[(i+1)%2][j];
                }
            }
            else{
                if(ops[i] <= j){
                    dp[i][j] = c[i];
                }
            }
            ans = max(ans, dp[i%2][j]);
        }
    }
    //ll ans = knapsack(ops, c, n-1, k, dp);
    cout << ans << nl;
    return;
}

void pre(){
    cnt[0] = cnt[1] = 0;
    for(int i = 1; i<N; i++){
        for(int x = 1; x<=i; x++){
            if(i+i/x <N)
                cnt[i+i/x] = min(cnt[i+i/x], 1+cnt[i]);
        }
    }
}

int main(){
    int T=1;
    pre();
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}