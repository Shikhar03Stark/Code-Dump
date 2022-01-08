// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(auto&e: arr){
        cin >> e;
    }
    ll times = 0;
    for(int i = 0; i<n; i++){
        while(arr[i]%2==0){
            arr[i] /= 2;
            times++;
        }
    }
    int idx = max_element(arr.begin(), arr.end()) - arr.begin();
    arr[idx] *= pow(2, times);
    ll sum = 0;
    for(auto& e: arr){
        sum += e;
    }
    cout << sum << nl;
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

