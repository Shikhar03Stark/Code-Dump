// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    ll n, L, a;
    cin >> n >> L >> a;
    if(n==0){
        cout << L/a << nl;
        return 0;
    }
    vector<pair<ll,ll>> cust(n);
    for(int i = 0; i<n; i++){
        ll a, b;
        cin >> a >> b;
        cust[i] = {a, a+b};
    }
    ll cig = 0;
    for(int i = 0; i<n-1; i++){
        int diff = cust[i+1].first - cust[i].second;
        cig += diff/a;
    }

    cig += (cust[0].first/a) + (L - cust[n-1].second)/a;
    cout << cig << nl;
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