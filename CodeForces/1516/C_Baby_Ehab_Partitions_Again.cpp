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

vector<vector<int>> dp(101, vector<int>(100*2000 + 1, -1));

bool subseq(vector<int> &arr, int target, int n){
    if(n < 0) return false;
    if(target == 0) return true;
    if(dp[n][target] != -1){
        return dp[n][target];
    }
    if(arr[n] <= target){
        return dp[n][target] = subseq(arr, target-arr[n], n-1) || subseq(arr, target, n-1);
    }
    else{
        return dp[n][target] = subseq(arr, target, n-1);
    }
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    int tot = 0;
    for(auto& e: arr){
        cin >> e;
        tot += e;
    }
    if(tot % 2 == 1){
        cout << 0 << nl;
        return;
    }

    bool pos = subseq(arr, tot/2, n-1);

    if(pos){
        bool hasodd = false;
        for(int i = 0; i<n; i++){
            if(arr[i]%2==1){
                hasodd = true;
                cout << 1 << nl;
                cout << i+1 << nl;
                return;
            }
        }
        cout << 2 << nl;
        cout << 1 << " " << 2 << nl;
    }
    else{
        cout << 0 << nl;
    }



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