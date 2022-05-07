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
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll lx = max(0LL, x-a);
    ll ly = max(0LL, y-b);
    if(lx+ly <= c){
        cout << "YES" << nl;
    }
    else{
        cout << "NO" << nl;
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