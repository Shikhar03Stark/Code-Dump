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
    string s;
    cin >> s;
    int n = s.size();
    stack<int> S;
    vector<int> dp(n, 0);
    for(int i = 0; i<n; i++){
        if(s[i] == '('){
            dp[i] = 0;
            S.push(i);
        }
        else{
            if(S.empty()){
                dp[i] = 0;
            }
            else{
                int prev = S.top();
                int dist = i-prev+1;
                int carry = (prev>0?dp[prev-1]:0);
                dp[i] = dist + carry;
                S.pop();
            }
        }
    }
    int ans = *max_element(dp.begin(), dp.end());
    int cnt = count(dp.begin(), dp.end(), ans);
    if(ans == 0){
        cnt = 1;
    }
    cout << ans << " " << cnt << nl;
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