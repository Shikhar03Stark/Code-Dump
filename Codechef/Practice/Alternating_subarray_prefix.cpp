#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int solve(vector<int> &arr, int n, vector<int> &dp){
    if(n <= 0){
        return dp[n] = 1;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    if(arr[n]*arr[n-1] == -1){
        return dp[n] = 1 + solve(arr, n-1, dp);
    }
    solve(arr, n-1, dp);
    return dp[n] = 1;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i<n; i++){
            int data;
            cin >> data;
            if(data > 0)
                arr[i] = 1;
            else
                arr[i] = -1;
        }
        reverse(begin(arr), end(arr));
        vector<int> dp(n,-1);
        solve(arr, n-1, dp);
        reverse(begin(dp), end(dp));
        for(auto& e: dp){
            cout << e << " ";
        }
        cout << endl;
    }
    return 0;
}