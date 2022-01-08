// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

bool isgood(vector<ll> &arr, ll k, ll h){
    int n = arr.size();
    for(int i = 0; i<n; i++){
        if(i==n-1){
            h -= k;
        }
        else{
            ll diff = arr[i+1]-arr[i];
            h -= min(k, diff);
        }
    }
    return h<=0;
}

int solve(){
    ll n, h;
    cin >> n >> h;
    vector<ll> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    ll low = 1, high = h+1;
    while(low<=high){
        ll k = low+(high-low)/2;
        if(isgood(arr, k, h)){
            high = k-1;
        }
        else{
            low = k+1;
        }
    }
    cout << low << endl;
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