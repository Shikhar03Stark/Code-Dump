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
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(auto &e: arr){
        cin >> e;
    }
    ll l = 0, r = n-1;
    ll suml = 0, sumr = 0;
    ll ans = 0;
    while(l<=r){
        if(suml < sumr){
            suml += arr[l++];
        }
        else if(suml > sumr){
            sumr += arr[r--];
        }
        
        if(suml == sumr){
            ans = max(ans, l+n-1-r);
            suml += arr[l++];
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