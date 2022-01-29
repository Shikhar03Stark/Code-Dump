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
    int x = (log(n)/log(10));
    ll ans = 9*x;
    ll inc = 0;
    for(int i = 0; i<=x; i++){
        inc = (inc*10) + 1;
    }
    ll num = 0;
    while(num+inc <= n){
        ans++;
        num += inc;
    }
    cout << ans << nl;
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