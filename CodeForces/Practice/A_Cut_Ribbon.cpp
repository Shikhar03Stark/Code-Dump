// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

vector<int> dp(4005, -1);

int count(int n, int a, int b, int c){
    if(n < min({a, b, c})){
        return -1e5;
    }
    if(dp[n] != -1) return dp[n];
    if(n==a || n==b || n==c){
        return dp[n] = max({1, 1+count(n-a, a, b, c), 1+count(n-b, a, b, c), 1+count(n-c, a, b, c)});
    }
    return dp[n] = 1+max({count(n-a, a, b, c), count(n-b, a, b, c), count(n-c, a, b, c)});
}

void solve(){
    int n, a, b, c;
    cin >>  n >> a >> b >> c;
    //if(n == min({a, b, c})){ cout << 0 << nl; return;}
    cout << count(n, a, b, c) << nl;
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