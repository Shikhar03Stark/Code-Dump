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

bool fill(vector<string> &grid, vector<vector<pair<int,int>>> &dp, int r, int c, vector<vector<bool>> &vis){
    int sr = r - dp[r+1][c+1].first + 1;
    int sc = c - dp[r+1][c+1].second + 1;
    for(int i = sr; i<=r; i++){
        for(int j = sc; j<=c; j++){
            if(vis[i][j] || grid[i][j]=='0'){
                return false;
            }
            vis[i][j] = true;
        }
    }

    return true;
}

bool fill2(vector<string> &grid, vector<vector<pair<int,int>>> &dp, int r, int c, vector<vector<bool>> &vis){
    int sr = r + dp[r][c].second - 1;
    int sc = c + dp[r][c].first - 1;
    for(int i = r; i<=sr; i++){
        for(int j = c; j<=sc; j++){
            if(vis[i][j] || grid[i][j]=='0'){
                return false;
            }
            vis[i][j] = true;
            // cerr << i+1 << " " << j+1 << nl;
        }
    }

    return true;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(int i = 0; i<n; i++){
        cin >> grid[i];
    }
    // vector<string> g2(n);
    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<m; j++){
    //         g2[i][j] = (grid[i][j]=='1'?'0':'1');
    //     }
    // }
    vector<vector<pair<int,int>>> dp(n+1, vector<pair<int,int>>(m+1, {0,0}));
    vector<vector<pair<int,int>>> dp2(n+1, vector<pair<int,int>>(m+1, {0,0}));
    // vector<vector<pair<int,int>>> dp2(n+1, vector<pair<int,int>>(m+1, {0,0}));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            // if(g2[i][j] == '1'){
            //     dp2[i+1][j+1] = {dp2[i][j+1].first + 1, dp2[i+1][j].second+1};
            // }
            if(grid[i][j] == '1'){
                dp[i+1][j+1] = {dp[i][j+1].first + 1, dp[i+1][j].second+1};
            }
        }
    }

    for(int i = n-1; i>=0; i--){
        for(int j = m-1; j>=0; j--){
            if(grid[i][j] == '1'){
                dp2[i][j] = {dp2[i][j+1].first+1, dp2[i+1][j].second + 1};
            }
        }
    }
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<bool>> vis2(n, vector<bool>(m, false));

    // vector<vector<bool>> vis2(n, vector<bool>(m, false));
    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<m; j++){
    //         cerr << "(" << dp2[i][j].first << "," << dp2[i][j].second << ") ";
    //     }
    //     cerr << nl;
    // }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] == '1'){
                if(!fill(grid, dp, i, j, vis) ){
                    cout << "NO" << nl;
                    return;
                }
            }
        }
    }

    for(int i = n-1; i>=0; i--){
        for(int j = m-1; j>=0; j--){
            if(grid[i][j] == '1'){
                if(!fill2(grid, dp2, i, j, vis2)){
                    cout << "NO" << nl;
                    return;
                }
            }
        }
    }
    // for(int i = n-1; i>=0; i--){
    //     for(int j = m-1; j>=0; j--){
    //         if(g2[i][j] == '1'){
    //             if(!fill(g2, dp2, i, j, vis2)){
    //                 cout << "NO" << nl;
    //                 return;
    //             }
    //         }
    //     }
    // }
    cout << "YES" << nl;



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