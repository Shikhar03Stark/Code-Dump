#include <bits/stdc++.h>
using namespace std;

int find(vector<int> &dsu, int x){
    return dsu[x]<0?x:dsu[x] = find(dsu, dsu[x]);
}

int dfs(vector<vector<int>> &grid, int r, int c, int pr, int pc, vector<vector<int>> &vis){
    int m = grid.size(), n = grid[0].size();
    if(r < 0 || r>=m || c<0 || c>=n || vis[r][c]==1 || grid[r][c] != grid[pr][pc]) return 0;
    int cc = 1;
    vis[r][c] = 1;
    int nr, nc;
    nr = r+1, nc = c;
    cc += dfs(grid, nr, nc, r, c, vis);
    nr = r, nc = c+1;
    cc += dfs(grid, nr, nc, r, c, vis);
    nr = r-1, nc = c;
    cc += dfs(grid, nr, nc, r, c, vis);
    nr = r, nc = c-1;
    cc += dfs(grid, nr, nc, r, c, vis);

    return cc;
}

void solve(vector<vector<int>> &grid){
    int m = grid.size(), n = grid[0].size();
    vector<int> dsu(m*n+1, -1);
    vector<vector<int>> vis(m, vector<int>(n,-1));
    int ansma = 0, ansmi = m*n+1;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(vis[i][j] == -1){
                int cc = dfs(grid, i, j, i, j, vis);
                ansma = max(ansma, cc);
                ansmi = min(ansmi, cc);
            }
        }
    }

    cout << "Largest CC: " << ansma << endl;
    cout << "Smallest CC: " << ansmi << endl;
}

int main(){
    int m = 0, n = 0;
    vector<vector<int>> grid = { { 1, 4, 4, 4, 4, 3, 3, 1 },
                        { 2, 1, 1, 4, 3, 3, 1, 1 },
                        { 3, 2, 1, 1, 2, 3, 2, 1 },
                        { 3, 3, 2, 1, 2, 2, 2, 2 },
                        { 3, 1, 3, 1, 1, 4, 4, 4 },
                        { 1, 1, 3, 1, 1, 4, 4, 4 } };

    solve(grid);

    return 0;
}