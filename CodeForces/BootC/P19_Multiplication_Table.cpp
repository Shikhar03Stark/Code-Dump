// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    ll n, x;
    cin >> n >> x;
    ll cnt = 0;
    for(ll i = 1; i*i<=x; i++){
        if(x%i == 0){
            if(i <= n && x/i <= n){
                if(i == x/i){
                    cnt++;
                }
                else{
                    cnt += 2;
                }
            }
        }
    }
    cout << cnt << nl;
    return;
}

int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}