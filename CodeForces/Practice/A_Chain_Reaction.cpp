// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int countBeacon(int n, vector<pair<int,int>> &arr, vector<int> &dp){
    if(n==0){
        return dp[n] = 1;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int newa = arr[n].first - arr[n].second;
    int x = lower_bound(arr.begin(), arr.end(), make_pair(newa,0)) - arr.begin();
    if(arr[x].first == newa || x==n){
        x--;
    }
    if(x==0 && arr[0].first>newa){
        return dp[n] = 1;
    }
    if(x < 0){
        return dp[n] = 1;
    }
    else{
        return dp[n] = 1+countBeacon(x, arr, dp);
    }
}

int solve(){
    int n;
    cin >> n;
    //vector<pair<int ,int>> arr(n);
    vector<int> b(1e6+5,0);
    for(int i = 0; i<n; i++){
        int a;
        cin >> a;
        cin >> b[a];
    }
    vector<int> dp(1e6+5,0);
    if(b[0]>0){
        dp[0] = 1;
    }
    int ans = 0;
    for(int i = 1; i<1e6+5; i++){
        if(b[i] == 0){
            dp[i] = dp[i-1];
        }
        else{
            if(b[i] >= i){
                dp[i] = 1;
            }
            else{
                dp[i] = 1+dp[i-b[i]-1];
            }
        }
        ans = max(ans, dp[i]);
    }
    //cerr << endl
    cout << n-ans << endl;

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