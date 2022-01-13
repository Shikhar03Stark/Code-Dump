// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    int n, l, k;
    cin >> n >> l >> k;
    vector<ll> s(n), d(n);
    for(int i = 0; i<n; i++){
        cin >> d[i];
    }
    d.push_back(l);
    for(int i = 0; i<n; i++){
        cin >> s[i];
    }
    s.push_back(0);
    vector<vector<ll>> dp(n+1, vector<ll>(k+1, 0));
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=k; j++){
            if(i == 0){
                dp[i][j] = 0;
            }
            if(i == 1 && j>0){
                dp[i][j] = dp[i][j-1];
            }
            if(j==0){
                if(i>0){
                    dp[i][j] = dp[i-1][j]+s[i-1]*(d[i]-d[i-1]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
            if(i>=2 && j>=1){
                ll val = INT_MAX;
                for(int r = 0; i-r-1>=0 && r<=j; r++){
                    val = min(val, dp[i-r-1][j-r] + s[i-r-1]*(d[i]-d[i-r-1]));
                }
                dp[i][j] = val;
            }
        }
    }

    cout << dp[n][k] << nl;

    return;
}

int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}