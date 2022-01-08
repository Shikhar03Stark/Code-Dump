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
    vector<int> arr(n+1);
    for(int i = 1; i<=n; i++){
        cin >> arr[i];
    }
    vector<int> dp(n+1,0);
    dp[1] = 1;
    for(int i = 2; i<=n; i++){
        int mx = 0;
        for(int j = 1; j*j<=i; j++){
            if(i%j==0){
                if(arr[j]<arr[i]){
                    mx = max(mx, dp[j]);
                }
                if(arr[i/j]<arr[i]){
                    mx = max(mx, dp[i/j]);
                }
            }
        }
        dp[i] = 1+mx;
    }

    cout << *max_element(dp.begin()+1, dp.end()) << endl;

    return 0;
}

int main(){
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}