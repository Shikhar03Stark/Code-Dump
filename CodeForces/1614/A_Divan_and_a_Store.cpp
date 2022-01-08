#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    ll n, l, r, k;
    cin >> n >> l >> r >> k;
    vector<ll> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    sort(arr.begin(), arr.end());
    int low = lower_bound(arr.begin(), arr.end(), l) - arr.begin();
    ll cnt = 0;
    for(int i = low; i<n && k>0; i++){
        if(k-arr[i]>=0 && arr[i]<=r){
            k -= arr[i];
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}