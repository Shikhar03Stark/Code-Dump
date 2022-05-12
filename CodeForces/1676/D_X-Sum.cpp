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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(auto& row: grid){
        for(auto& e: row){
            cin >> e;
        }
    }
    vector<int> d1(n+m-1, 0), d2(n+m-1, 0) ;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            d1[i+j] += grid[i][j];
            d2[m-1 + i - j] += grid[i][j];
        }
    }
    // for(int i = 0; i<n+m; i++){
    //     cerr << i << " " << d1[i] << " " << d2[i] << nl;
    // }
    // cerr << nl;
    int ans = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            ans = max({ans, d1[i+j]+ d2[m-1+i-j] - grid[i][j]});
        }
    }
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