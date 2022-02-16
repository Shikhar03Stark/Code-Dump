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
    ll k;
    cin >> k;
    ll b = 1;
    while(k>b*b){
        b++;
    }
    //cerr << "(" << b-1 << "," << b << "]" << nl;
    ll k2 = k-(b-1)*(b-1)-1;
    //cerr << k2 << nl;
    k2 = (k2%(2*b-1)) - (2*b-1)/2;
    //cerr << k2 << nl;
    if(k2<=0){
        cout << b+k2 << ' ' << b << nl;
    }
    else{
        cout << b << ' ' << b-k2 << nl;
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