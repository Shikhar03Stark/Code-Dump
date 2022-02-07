// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

const int MAXN = 1e5+1;

vector<int> pf(int n){
    vector<int> ans;
    for(int i = 2; i*i<=n; i++){
        if(n%i==0){
            ans.push_back(i);
            while(n%i==0){
                n /= i;
            }
        }
    }
    if(n>1){
        ans.push_back(n);
    }

    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    unordered_map<int,int> h;
    //unordered_map<int, int> connected;
    vector<int> dp(n,1);
    for(int i = 0; i<n; i++){
        vector<int> f = pf(arr[i]);
        bool found = false;
        for(int j = 0; j<f.size(); j++){
            if(h.count(f[j]) > 0){
                found = true;
                dp[i] = max(dp[i], 1+dp[h[f[j]]]);
            }
            h[f[j]] = i;
        }
    }
    int ans = *max_element(dp.begin(), dp.end());
    cout << ans << nl;
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