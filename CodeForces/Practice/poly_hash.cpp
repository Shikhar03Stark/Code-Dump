// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

const ll p = 31;
const ll m = 1e9+7;

void pre(){
    
    return;
}

ll make_hash(const string& s){
    ll mult = 1;
    ll ans = 0;
    for(auto& c: s){
        ans = (ans + (c-'a'+1)*mult) % m;
        mult = (mult*p) % m;
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<string> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    vector<pair<ll,int>> ans(n);
    for(int i = 0; i<n; i++){
        ans[i] = {make_hash(arr[i]), i};
    }
    sort(ans.begin(), ans.end());
    int g = 1;
    for(int i = 1; i<n; i++){
        if(ans[i].first != ans[i-1].first) g++;
    }
    cout << "Number of groups: " << g << nl;
    for(auto& p: ans){
        cerr << p.first << " " << arr[p.second] << nl;
    }
    return;
}

int main(){
    FASTIO
    pre();
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}