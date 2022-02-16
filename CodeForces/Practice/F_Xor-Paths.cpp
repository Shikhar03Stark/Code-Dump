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
int m, n;
ll k;
int ans = 0;
ll dfs(vector<vector<ll>> &grid, int r, int c, ll x){
    if(r<0 || r>m || c<0 || c>n) return 0;
    // cerr << '(' << r << "," << c << ") " << (x^grid[r][c]) << " ";
    if(r==m && c==n){
        if((x^grid[r][c])==k){
            return 1;
        }
        return 0;
    }
    return dfs(grid, r+1, c, x^grid[r][c]) + dfs(grid, r, c+1, x^grid[r][c]);
}
void solve(){
    cin >> m >> n >> k;
    vector<vector<ll>> grid(m, vector<ll>(n, 0));
    for(auto& row: grid){
        for(auto& e: row){
            cin >> e;
        }
    }
    m--;
    n--;
    ll ans = dfs(grid, 0, 0, 0LL);
    cout << ans << nl;
    return;
}

int main(){
    FASTIO
    pre();
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}