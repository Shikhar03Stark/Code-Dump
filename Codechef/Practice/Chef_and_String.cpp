#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int solve(string &s, int n, vector<int> &dp){
    if(n <= 0) return 0;
    if(dp[n] != -1){
        return dp[n];
    }
    if(s[n] != s[n-1]){
        return dp[n] = max(1+solve(s, n-2, dp), solve(s, n-1, dp));
    }
    return dp[n] = solve(s, n-1, dp);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        vector<int> dp(n,-1);
        int ans = solve(s, n-1, dp);
        cout << ans << endl;
    }
    return 0;
}