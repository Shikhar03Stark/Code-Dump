// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;


int n, m;
bool inside(int r, int c){
    if(r<0 || r>=n || c<0 || c>=m) return false;
    return true;
}
int dfs(vector<vector<int>> &grid, int r, int c, vector<vector<int>> &vis, int colour){
    if(r<0 || r>= n || c<0 || c>=m || vis[r][c]) return 0;
    vis[r][c] = colour;
    int ans = 1;
    int dir = grid[r][c];
    if((dir&8) == 0){
        if(inside(r-1, c) && (grid[r-1][c]&2)==0)
            ans += dfs(grid, r-1, c, vis, colour);
    }
    if((dir&4) == 0){
        if(inside(r, c+1) && (grid[r][c+1]&1) == 0)
            ans += dfs(grid, r, c+1, vis, colour);
    }
    if((dir&2) == 0){
        if(inside(r+1, c) && (grid[r+1][c]&8) == 0)
            ans += dfs(grid, r+1, c, vis, colour);
    }
    if((dir&1) == 0){
        if(inside(r, c-1) && (grid[r][c-1]&4) == 0)
            ans += dfs(grid, r, c-1, vis, colour);
    }

    return ans;
}

void solve(){
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    vector<vector<int>> vis(n, vector<int>(m,0));
    for(auto& row: grid){
        for(auto& e: row){
            cin >> e;
        }
    }

    vector<int> rooms;
    int col = 1;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(!vis[i][j]){
                int size = dfs(grid, i, j, vis, col);
                rooms.push_back(size);
                col++;
            }
        }
    }

    // for(auto& row: vis){
    //     for(auto& e: row){
    //         cerr << e << " ";
    //     }
    //     cerr << nl;
    // }

    sort(rooms.rbegin(), rooms.rend());
    for(auto& e: rooms){
        cout << e << ' ';
    }
    cout << nl;

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