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

bool possible(vector<ll> &arr, ll x, ll n, ll sz){
    ll sum = 0;
    // int n = arr.size();
    for(int i = sz-1; i>=n-x; i--){
        sum += n-arr[i];
        if(sum >= n) return false;
    }
    return true;
}

void solve(){
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(k);
    for(auto& e: arr){
        cin >> e;
    }
    sort(arr.begin(), arr.end());
    int ans = 0;
    ll sum = 0;
    for(int i = k-1; i>=0; i--){
        sum += n-arr[i];
        if(sum >= n){
            break;
        }
        ans++;
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