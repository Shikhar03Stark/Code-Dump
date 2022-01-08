// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;
const int sz = 2e5+5;
const int mod = 1e9+7;

ll facto[sz];


void solve(){
    int n;
    cin >> n;
    cout << facto[2*n] << nl;
    return;
}

int main(){
    facto[0] = facto[1] = 1, facto[2] = 1;
    for(ll i = 3; i<sz; i++){
        facto[i] = (facto[i-1]*i)%mod;
    }
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}