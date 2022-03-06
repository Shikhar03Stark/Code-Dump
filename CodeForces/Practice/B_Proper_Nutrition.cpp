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

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}


void solve(){
    ll n, a, b;
    cin >> n >> a >> b;
    ll g = __gcd(a, b);
    bool pos = false;
    if(n%g==0 && n>=min(a, b)){
        // cout << "YES" << nl;
        for(ll x = 0; x<=1e7; x++){
            double d = (n-a*x+0.0)/b;
            if(ceil(d) == floor(d) && d>=0){
                cout << "YES" << nl;
                cout << x << " " << (ll)d << nl;
                return;
            }
        }
        cout << "NO" << nl;
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
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}