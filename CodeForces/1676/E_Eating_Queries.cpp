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
    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for(auto&e: arr){
        cin >> e;
    }
    sort(arr.rbegin(), arr.rend());
    vector<ll> pre(n, 0);
    pre [0] = arr[0];
    for(int i = 1; i<n; i++){
        pre[i] = pre[i-1] + arr[i];
    }
    // for(auto& e: pre){
    //     cerr << e << " ";
    // }
    // cerr << nl;
    for(int _ = 0; _<q; _++){
        ll x;
        cin >> x;
        int lb = lower_bound(pre.begin(), pre.end(), x) - pre.begin();
        // cerr << lb << nl;
        if(lb == n){
            cout << -1 << nl;
        }
        else{
            cout << lb+1 << nl;
        }
    }
    // cerr << nl;
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