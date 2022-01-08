// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

vector<vector<int>> dp(101, vector<int>(101, -1));

int cuts(vector<int> &arr, vector<int> &evens, int start, int b, int n){
    if(b<=0) return 0;
    if(start >= n-1) return 0;
    if(dp[start][b] != -1){
        return dp[start][b];
    }
    for(int i = start; i<n-1; i++){
        int e = evens[i] - (start==0?0:evens[start-1]);
        if(2*e == i-start+1){
            if(abs(arr[i]-arr[i+1]) <= b){
                return max(1+cuts(arr, evens, i+1, b-abs(arr[i]-arr[i+1]), n), cuts(arr, evens, i+1, b, n));
            }
            else{
                return cuts(arr, evens, i+1, b, n);
            }
        }
    }

    return 0;
}

void solve(){
    int n,b;
    cin >> n >> b;
    vector<int> arr(n), even(n);
    for(auto& e: arr){
        cin >> e;
    }
    even[0] = (arr[0]%2==0?1:0);
    for(int i = 1; i<n; i++){
        even[i] = even[i-1] + (arr[i]%2==0?1:0);
    }

    cout << cuts(arr, even, 0, b, n) << nl;
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