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
    ll a, b;
    cin >> a >> b;
    ll lcm = a*b/__gcd(a, b);
    ll m1 = lcm/a, m2 = lcm/b;
    if(m1>m2){
        if(m1-m2==1){
            if(b>a){
                cout << "Equal" << nl;
                return;
            }
        }
        cout << "Dasha" << nl;
    }
    else if(m1<m2){
        if(m2-m1==1){
            if(a>b){
                cout << "Equal" << nl;
                return;
            }
        }
        cout << "Masha" << nl;
    }
    else{
        cout << "Equal" << nl;
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