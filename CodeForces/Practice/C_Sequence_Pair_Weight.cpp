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


ll cnt(vector<int> &arr, int l, int r){
    if(l>=r) return 0;
    ll mid = l + (r-l)/2;
    ll leftseg = cnt(arr, l, mid);
    ll rightseg = cnt(arr, mid+1, r);
    auto itr = arr.begin();
    vector<int> aux(r-l+1);
    merge(itr+l, itr+mid+1, itr+mid+1, itr+r+1, aux.begin());
    for(int i = l; i<=r; i++){
        arr[i] = aux[i-l];
    }
    ll ans = leftseg + rightseg;
    ll c = 0;
    for(int i = l; i<=r; i++){
        if(i!=l){
            if(arr[i] != arr[i-1]){
                ans += (c>=2?c*(c-1)/2:0);
                c=1;
            }
            else{
                c++;
            }
        }
        else{
            c++;
        }
    }

    ans += (c>=2?c*(c-1)/2:0);

    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    map<int, ll> h;
    vector<ll> dp(n);
    //dp[0] = 0;
    //h[arr[0]]++;
    ll ans = 0;
    for(int i = 0; i<n; i++){
        // dp[i] = dp[i-1];
        // dp[i] += h[arr[i]];
        // h[arr[i]];
        // ans += dp[i];
        if (i)
            dp[i] = dp[i-1];
        dp[i] += h[arr[i]];

        h[arr[i]] += i+1;
        ans += dp[i];
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