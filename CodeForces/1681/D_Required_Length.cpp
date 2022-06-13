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

int f(ll x, ll n){
    ll t = x;
    set<int> d;
    ll len = 0;
    while(t){
        // d = max(d, t%10);
        d.insert(t%10);
        t /= 10;
        len++;
    }
    cerr << len << " " << x << nl;
    if(len >= n) return 0;
    int ans = 1000;
    vector<int> di(d.rbegin(), d.rend());

    for(int i = 0; i<min(1, (int)di.size()); i++){
        if(di[i] > 1){
            ans = min(ans, 1 + f(x*di[i], n));
        }
    }
    return ans;

}

void solve(){
    ll n, x;
    cin >> n >> x;
    if(x == 0 && n == 1){
        cout << 0 << nl;
        return;
    }
    else if(x == 0 && n > 1){
        cout << -1 << nl;
        return;
    }
    int ops = f(x, n);
    if(ops >= 20){
        cout << -1 << nl;
        return;
    }
    cout << ops << nl;

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