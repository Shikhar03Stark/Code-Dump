// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    ll sum = 0;
    for(auto& e: arr){
        cin >> e;
        sum += e;
    }
    if(sum <= k){
        cout << 0 << nl;
        return 0;
    }
    sort(arr.begin(), arr.end());
    vector<ll> suf(n+1);
    for(int i = 0; i<n; i++){
        suf[i+1] = suf[i] + arr[n-i-1];
    }
    ll steps = INT_MAX;
    for(ll y = 0; y<n; y++){
        ll nr = sum + arr[0]*y - suf[y] - k;
        double dr = 1+y;
        double r = nr/dr;
        steps = min(steps, max(0LL, (ll)ceil(r))+y);
    }

    cout << steps << nl;

    return 0;
}

int main(){
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}