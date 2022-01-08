// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    ll l, r;
    cin >> l >> r;
    vector<bool> a,b;
    ll t = l;
    while(t){
        a.push_back(t%2);
        t /= 2;
    }
    t = r;
    while(t){
        b.push_back(t%2);
        t /= 2;
    }
    int ms = max(a.size(), b.size());
    a.resize(ms);
    b.resize(ms);
    vector<bool> ans(ms);
    for(int i = ms-1; i>=0; i--){
        if(a[i]^b[i]==1){
            ans[i] = 1;
        }
        else{
            ll t = (l^(1LL<<i));
            if(l<=t && t<=r){
                ans[i] = 1;
                continue;
            }
            t = (r^(1LL<<i));
            if(l<=t && t<=r){
                ans[i] = 1;
                continue;
            }
            ans[i] = 0;
        }
        cerr << ans[i];
    }
    ll res = 0;
    for(int i = 0; i<ans.size(); i++){
        res += ans[i]*(1LL<<i);
        cerr << nl << res;
    }
    cout << (ll)res << nl;
    return 0;
}

int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}