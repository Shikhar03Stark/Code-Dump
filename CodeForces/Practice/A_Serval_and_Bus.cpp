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
    int n, t;
    cin >> n >> t;
    vector<pair<int,int>> arr(n);
    for(auto& e: arr){
        cin >> e.first >> e.second;
    }
    int ans = -1;
    int mindist = INT_MAX;
    for(int i = 0; i<n; i++){
        int ts = max(0.0,ceil((t-arr[i].first+0.0)/arr[i].second));
        if(ans < 0){
            ans = i+1;
            mindist = arr[i].first + arr[i].second*ts - t;
        }
        if(arr[i].first + arr[i].second*ts - t < mindist){
            ans = i+1;
            mindist = arr[i].first + arr[i].second*ts - t;
        }
    }
    cout << ans << nl;
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