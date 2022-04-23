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
    ll n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    vector<int> bit(31, 0);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<=30; j++){
            bit[j] += ((arr[i]&(1<<j))>0)?1:0;
        }
    }

    for(int j = 30; j>=0; j--){
        if(n-bit[j] <= k){
            k -= (n - bit[j]);
            bit[j] = n;
        }
    }

    ll ans = 0;
    for(int i = 0; i<=30; i++){
        if(bit[i] == n){
            ans += (1<<i);
        }
    }
    cout << ans << nl;

    return;
}

int main(){
    FASTIO
    pre();
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}