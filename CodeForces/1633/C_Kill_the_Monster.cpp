// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    ll hc_, dc_, hm_, dm_, k, w, a;
    cin >> hc_ >> dc_;
    cin >> hm_ >> dm_;
    cin >> k >> w >> a;
    for(ll x = 0; x<=k; x++){
        ll hc, dc, hm, dm;
        hc = hc_ + x*a;
        dc = dc_ + (k-x)*w;
        hm = hm_;
        dm = dm_;

        ll n = ceil((0.0+hc)/dm);//(hc%dm)?hc/dm:hc/dm-1;
        ll m = ceil((0.0+hm)/dc);
        if(m<=n){
            cout << "YES" << nl;
            return;
        }
    }
    cout << "NO" << nl;
    return;
}

int main(){
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}