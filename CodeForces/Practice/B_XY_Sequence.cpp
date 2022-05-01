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
    ll n, B, x, y;
    cin >> n >> B >> x >> y;
    ll sum = 0;
    ll p = 0;
    for(int i = 0; i<n; i++){
        if((p+x) > B){
            p -= y;
        }
        else{
            p += x;
        }
        sum += p;
    }
    cout << sum << nl;
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