// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    ll w, h;
    cin >> w >> h;
    vector<vector<ll>> X(2), Y(2);
    int k;
    cin >> k;
    X[0].resize(k);
    for(int i = 0; i<k; i++){
        cin >> X[0][i];
    }
    cin >> k;
    X[1].resize(k);
    for(int i = 0; i<k; i++){
        cin >> X[1][i];
    }
    cin >> k;
    Y[0].resize(k);
    for(int i = 0; i<k; i++){
        cin >> Y[0][i];
    }
    cin >> k;
    Y[1].resize(k);
    for(int i = 0; i<k; i++){
        cin >> Y[1][i];
    }

    ll ans = 0;

    {
        // X-axis base
        ll a1 = (X[0][X[0].size()-1] - X[0][0])*(h);
        ll a2 = (X[1][X[1].size()-1] - X[1][0])*(h);

        ans = max({ans, a1, a2});
    }

    {
        // Y-axis base
        ll a1 = (Y[0][Y[0].size()-1] - Y[0][0])*(w);
        ll a2 = (Y[1][Y[1].size()-1] - Y[1][0])*(w);

        ans = max({ans, a1, a2});
    }

    cout << ans << nl;

    return 0;
}

int main(){
    FASTIO
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}