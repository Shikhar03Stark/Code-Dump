// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    int n;
    cin >> n;
    set<ll> S;
    for(int i = 0; i<n; i++){
        ll d;
        cin >> d;
        S.insert(d);
    }
    vector<ll> d(n-1);
    auto it = S.begin();
    ll prev = *it;
    it++;
    for(;it!=S.end(); it++){
        d.push_back((*it)-prev);
        prev = *it;
    }
    sort(d.begin(), d.end());
    int sz = d.size();
    vector<ll> pre(sz+1,0);
    for(int i = 0; i<sz; i++){
        pre[i+1] = pre[i] + d[i];
    }
    int q;
    cin >> q;
    for(int que=0; que<q; que++){
        ll l, r;
        cin >> l >> r;
        ll delta = r-l+1;
        ll ans = r-l+1;
        ll up = upper_bound(d.begin(), d.end(), delta) - d.begin();
        ans += pre[up];
        ans += delta*(sz-up);
        cout << ans << " ";
    }

    return;
}

int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}