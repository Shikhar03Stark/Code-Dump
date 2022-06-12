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
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    vector<vector<int>> mindp(n+1, vector<int>(n+1, 0)), maxdp(n+1, vector<int>(n+1, 0));
    for(int c= 1; c<=n; c++){
        for(int i = 0; i<n; i++){
            if(arr[i] < c){
                mindp[c][i+1] = 1;
            }
            if(arr[i] > c){
                maxdp[c][i+1] = 1;
            }
            mindp[c][i+1] += mindp[c][i];
            maxdp[c][i+1] += maxdp[c][i];
            // cerr << maxdp[c][i+1] << ' ';
        }
        // cerr << nl;
    }

    ll ans = 0;
    for(int b = 0; b<n; b++){
        for(int c = b+1; c<n; c++){
            ll na = mindp[arr[c]][b];
            ll nd = mindp[arr[b]][n] - mindp[arr[b]][c+1];
            // cerr << na << " " << arr[b] << " " << arr[c] << " " << nd << nl;
            ans += na*nd;
        }
    }
    // cerr << nl;
    cout << ans << nl;
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