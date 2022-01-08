#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    map<int,int> h;
    for(auto& e:arr){
        cin >> e;
        h[e]++;
    }
    vector<ll> dp(1e5+1, 0);
    dp[0] = 0;
    dp[1] = h[1];
    ll ans = 0;
    for(int i = 2; i<=1e5; i++){
        dp[i] = max(dp[i-1], dp[i-2] + (ll)h[i]*i);
        ans = max(ans, dp[i]);
    }
    
    cout << ans << endl;
    return 0;
}