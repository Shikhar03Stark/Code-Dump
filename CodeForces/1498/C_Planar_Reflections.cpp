#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int

using namespace std;

ll mod = 1e9 + 7;
ll solve(int z, int k, int n, vector<vector<ll>>& memo){
    if(z <= 0){
        return 1;
    }
    if(k <= 1){
        return 1;
    }
    if(memo[z][k] != -1){
        return memo[z][k];
    }
    return memo[z][k] = (solve(n-z, k-1, n, memo)%mod + solve(z-1, k, n, memo)%mod)%mod;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<vector<ll>> memo(n+1, vector<ll>(k+1,-1));
        cout << solve(n, k, n, memo) << endl;

    }
    return 0;
}