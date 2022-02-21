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
    for(auto& e: arr){
        cin >> e;
    }
    int li = n-2, hi = n-1;
    if(arr[n-2] > arr[n-1]){
        cout << -1 << nl;
        return;
    }
    if(arr[n-1]<0){
        if(is_sorted(arr.begin(), arr.end())){
            cout << 0 << nl;
            return;
        }
        else{
            cout << -1 << nl;
            return;
        }
    }
    vector<tuple<int,int,int>> ans;
    for(int i = n-3; i>=0; i--){
        if(arr[i]>arr[li]){
            arr[i] = arr[li] - arr[hi];
            ans.push_back({i+1, li+1, hi+1});
        }
        if(arr[i] > arr[li]){
            cout << -1 << nl;
            return;
        }
        if(arr[li] > arr[i]){
            li = i;
        }
    }
    cout << ans.size() << nl;
    for(auto& t: ans){
        cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << nl;
    }

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