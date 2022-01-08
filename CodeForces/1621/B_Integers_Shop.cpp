// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    int n;
    cin >> n;
    ll mi = 2e14, cmi = 2e14;
    ll ma = 0, cma = 2e14;
    ll len = 0, clen = 2e14;
    for(int i = 0; i<n; i++){
        ll l,r,c;
        cin >> l >> r >> c;
        if(l < mi){
            mi = l;
            cmi = c;
        }
        if(l == mi){
            cmi = min(cmi, c);
        }

        if(r > ma){
            ma = r;
            cma = c;
        }
        if(r == ma){
            cma = min(cma, c);
        }

        if(len < r-l+1){
            len = r-l+1;
            clen = c;
        }
        if(len == r-l+1){
            clen = min(clen, c);
        }

        ll ans = cmi + cma;
        if(len == ma-mi+1){
            ans = min(ans, clen);
        }
        cout << ans << nl;
    }
    return 0;
}

int main(){
    FASTIO
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}