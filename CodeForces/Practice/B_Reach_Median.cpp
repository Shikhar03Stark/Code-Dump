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
    ll n, s;
    cin >> n >> s;
    vector<ll> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    sort(arr.begin(), arr.end());
    ll ans = 0;
    if(arr[n/2]<=s){
        for(int i = n/2; i<n; i++){
            ans += max(s-arr[i], 0LL);
        }
    }
    else{
        for(int i = n/2; i>=0; i--){
            ans += max(arr[i]-s, 0LL);
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