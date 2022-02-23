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

tuple<ll,ll,ll> kadane(vector<ll> &arr){
    int n = arr.size();
    ll max_so_far = INT_MIN, max_ending_here = 0,
       start =0, end = 0, s=0;
  
    for (int i=0; i<n; i++ )
    {
        max_ending_here += arr[i];
  
        if (max_so_far <= max_ending_here)
        {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }
  
        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            s = i + 1;
        }
    }
    if(max_so_far<0){
        return {0, start, end};
    }

    return {max_so_far, start, end};
}

void solve(){
    ll n, x;
    cin >> n >> x;
    vector<ll> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    vector<ll> ssum(n+1, INT_MIN);
    ll msum = INT_MIN;
    for(int i = 0; i<n; i++){
        ll sum = 0;
        for(int j = i; j<n; j++){
            sum += arr[j];
            ssum[j-i+1] = max(ssum[j-i+1], sum);
            msum = max(msum, ssum[j-i+1]);
        }
    }
    vector<ll> ans(n+1);
    ans[n] = ssum[n];
    // for(auto& e: ssum){
    //     cerr << e << " ";
    // }
    for(int i = n-1; i>=0; i--){
        ans[i] = max(ssum[i], ans[i+1]);
        //cerr << ans[i] << " ";
    }
    // cerr << nl;
    cout << max(0LL, msum) << " ";
    for(int i = 1; i<=n; i++){
        ll r = max({0LL, msum, ans[i]+x*i});
        cout << r << " ";
        msum = r;
    }
    cout << nl;
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