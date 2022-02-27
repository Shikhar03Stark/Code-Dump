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
    vector<ll> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    ll ans = n*(n-1) - k*(arr[n-1]|arr[n-2]);
    for(ll i = 0; i<n; i++){
        for(ll j = max(0LL,n-2*k-1); j<n; j++){
            if (i!=j)
                ans = max(ans, (i+1)*(j+1) - k*(arr[i]|arr[j]));
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