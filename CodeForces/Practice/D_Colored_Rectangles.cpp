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

ll f(vector<vector<ll>> &color, int n, int m, int p, vector<vector<vector<ll>>> &dp){
    int sum = n+m+p;
    if(sum == n || sum == m || sum == p){
        return 0;
    }
    if(dp[n][m][p] != -1){
        return dp[n][m][p];
    }
    if(sum-n == sum || sum-m == sum || sum-p == sum){
        if(n==0){
            return dp[n][m][p] = color[1][m-1]*color[2][p-1] + f(color, n, m-1, p-1, dp);
        }
        else if(m == 0){
            return dp[n][m][p] = color[0][n-1]*color[2][p-1] + f(color, n-1, m, p-1, dp);
        }
        else{
            return dp[n][m][p] = color[0][n-1]*color[1][m-1] + f(color, n-1, m-1, p, dp);
        }
    }
    else{
        return dp[n][m][p] = max({
            color[0][n-1]*color[1][m-1] + f(color, n-1, m-1, p, dp),
            color[0][n-1]*color[2][p-1] + f(color, n-1, m, p-1, dp),
            color[1][m-1]*color[2][p-1] + f(color, n, m-1, p-1, dp)
        });
    }
}

void solve(){
    vector<int> sz(3);
    cin >> sz[0] >> sz[1] >> sz[2];
    vector<vector<ll>> color(3);
    for(int i = 0; i<3; i++){
        color[i].resize(sz[i]);
        for(int j = 0; j<sz[i]; j++){
            cin >> color[i][j];
        }
    }
    sort(color[0].begin(), color[0].end());
    sort(color[1].begin(), color[1].end());
    sort(color[2].begin(), color[2].end());

    vector<vector<vector<ll>>> dp(sz[0]+1,
        vector<vector<ll>>(sz[1]+1, 
            vector<ll>(sz[2]+1, -1)));
    ll ans = f(color, sz[0], sz[1], sz[2], dp);
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