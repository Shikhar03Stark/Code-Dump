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
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    sort(arr.begin(), arr.end());
    map<ll,ll> freq;
    vector<ll> uniq;
    for(int i = 0; i<n; i++){
        if(i){
            if(uniq.back() != arr[i]){
                uniq.push_back(arr[i]);
            }
        }
        else{
            uniq.push_back(arr[i]);
        }
        freq[arr[i]]++;
    }
    vector<int> ans(uniq.size(), 0);
    int asz = ans.size();
    int l = -1, r = -1, maxa = 0;
    for(int i = 0; i<asz; i++){
        if(i){
            if(uniq[i] - uniq[i-1] == 1 && freq[uniq[i]] >= k){
                ans[i] = ans[i-1] + 1;
            }
            else if(freq[uniq[i]] >= k){
                ans[i] = 1;
            }
        }
        else{
            if(freq[uniq[i]] >= k){
                ans[i] = 1;
            }
        }
        if(maxa < ans[i]){
            r = uniq[i];
            l = r - ans[i] + 1;
            maxa = ans[i];
        }
    }
    if(l == -1){
        cout << -1 << nl;
    }
    else{
        cout << l << " " << r << nl;
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