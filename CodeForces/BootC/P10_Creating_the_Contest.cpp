// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    vector<int> dp(n, 0);
    dp[0] = 1;
    for(int i = 1; i<n; i++){
        if(arr[i-1]>=ceil(arr[i]/2.0)){
            dp[i] = dp[i-1]+1;
        }
        else{
            dp[i] = 1;
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
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