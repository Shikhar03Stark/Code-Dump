// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

bool lte(ll x, ll n, ll k){
    ll sum = k*x - x*(x+1)/2;
    cerr << x << ":" << n-sum-1 << nl;
    return sum <= n-1;
}

void solve(){
    ll n, k;
    cin >> n >> k;
    if(n > 1+ k*(k-1)/2){
        cout << -1 << nl;
        return;
    }
    if(n==1){
        cout << 0 << nl;
        return;
    }
    
    ll low = 1, high = k-1, ans = 0;
    while(low<=high){
        ll mid = low+(high-low)/2;
        if(lte(mid, n, k)){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    if(k*ans - ans*(ans+1)/2 == n-1){
        cout << ans << nl;
    }
    else{
        cout << ans+1 << nl;
    }

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