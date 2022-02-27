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
    ll n, a, b;
    cin >> n >> a >> b;
    if(a == 1){
        if((n-1)%b == 0){
            cout << "Yes" << nl;
            return;
        }
        else{
            cout << "No" << nl;
            return;
        }
    }
    for(ll x = 1; x<=n; x *= a){
        if((n-x)%b == 0){
            cout << "Yes" << nl;
            return;
        }
    }
    cout << "No" << nl;
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