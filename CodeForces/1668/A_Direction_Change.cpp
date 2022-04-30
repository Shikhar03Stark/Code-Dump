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

ll steps(ll n, ll m){
    if(n == m){
        return 2*(n-1);
    }
    if(n == 2) return steps(m, n);
    if(n%2 == 1){
        return 2*n - 3;
    }
    else{
        return 2*n - 2;
    }
}

void solve(){
    ll n, m;
    cin >> n >> m;
    if(n == 1 || m == 1){
        if(n*m <= 2){
            if(n == m){
                cout << 0 << nl;
                return;
            }
            else{
                cout << 1 << nl;
                return;
            }
        }
        cout << -1 << nl;
        return;
    }
    ll sq = min((n-1), (m-1));
    ll ans = max(0LL, 2*(sq-1));
    n -= sq-1;
    m -= sq-1;
    ans += steps(n, m);

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