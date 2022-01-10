// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    ll n;
    cin >> n;
    ll t = n;
    vector<vector<int>> digits(2);
    for(int i = 0; t>0; i++){
        digits[i%2].push_back(t%10);
        t/=10;
    }
    ll a = 0, b = 0;
    for(int i = 0; i<max(digits[0].size(), digits[1].size()); i++){
        if(i<digits[0].size()){
            a += digits[0][i]*pow(10,i);
        }
        if(i<digits[1].size()){
            b += digits[1][i]*pow(10,i);
        }
    }
    ll ans = (a+1)*(b+1) - 2;
    cout << ans << nl;
    return;
}

int main(){
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}