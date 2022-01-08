#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

class Solution {

public : 

        int sx,sy, m, n, ans=0, empty=1;
    void dfs(vector<vector<int>>& grid, int x, int y){
        if(x<0 || y< 0 || x>=m || y>=n){
            return;
        }
        if(grid[x][y] < 0)
            return;
        if(grid[x][y] == 2){
            if(empty==0)
                ans++;
            return;
        }
        --empty;
        grid[x][y] = -2;
        dfs(grid, x+1, y);
        dfs(grid, x-1, y);
        dfs(grid, x, y+1);
        dfs(grid, x, y-1);
        grid[x][y] = 0;
        ++empty;
        
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for(int i = 0; i<m; i++)
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1){
                    sx = i;
                    sy = j;
                }
                if(grid[i][j] == 0){
                    empty++;
                }
            }
        
        dfs(grid, sx, sy);
        
        return ans;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid = 
    {
        {1,0,0,0},
        {0,0,0,0},
        {0,0,2,-1}
    };

    int res = sol.uniquePathsIII(grid);
    cout << res << endl;

    return 0;
}
