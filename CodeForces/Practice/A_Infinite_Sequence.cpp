// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    ll n;
    cin >> n;
    ll k = (sqrt(1.0+8*n) - 1)/2.0;
    //cerr << k << nl;
    ll sum = (k*(k+1))/2;
    ll del = n - sum;
    if(del == 0){
        cout << k << nl;
    }
    else{
        cout << del << nl;
    }
    return 0;
}

int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}