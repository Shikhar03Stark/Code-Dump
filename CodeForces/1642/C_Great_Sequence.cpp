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
    ll n, x;
    cin >> n >> x;
    vector<ll> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    sort(arr.begin(), arr.end());
    map<ll, ll> cnt;
    for(int i = 0; i<n; i++){
        if(arr[i]%x == 0 && cnt[arr[i]/x] > 0){
            cnt[arr[i]/x]--;
        }
        else{
            cnt[arr[i]]++;
        }
    }
    int left = 0;
    for(auto& p: cnt){
        left += p.second;
    }
    cout << left << nl;
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