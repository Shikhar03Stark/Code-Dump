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
    ll n, g;
    cin >> n >> g;
    vector<ll> arr(g);
    for(auto& e: arr){
        cin >> e;
    }
    sort(arr.begin(), arr.end());
    ll sum = 0;
    for(int i = 0; i<n; i++){
        sum += arr[i];
    }
    cout << sum << nl;
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