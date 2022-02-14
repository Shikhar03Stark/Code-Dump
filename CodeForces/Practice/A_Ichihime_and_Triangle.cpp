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

bool valid(ll a, ll b, ll c){
    if(a+b<=c) return false;
    if(b+c<=a) return false;
    if(c+a<=b) return false;
    return true;
}

void solve(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    for(auto x: {a,b}){
        for(auto y: {b,c}){
            for(auto z : {c,d}){
                if(valid(x, y, z)){
                    cout << x << ' ' << y << ' ' << z << nl;
                    return;
                }
            }
        }
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