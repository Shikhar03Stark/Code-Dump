#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;


class Solution {

public : 
    void adjustGrid(vector<vector<char>> & grid, int i, int j){
        int y = grid.size();
        int x = grid[0].size();
        if(i < 0 || i>=y || j<0 || j>=x || grid[i][j] != '1'){
            return;
        }
        grid[i][j] = '0';
        adjustGrid(grid, i+1, j);
        adjustGrid(grid, i-1, j);
        adjustGrid(grid, i, j+1);
        adjustGrid(grid, i, j-1);
    }
    
    int numIslands(vector<vector<char>> grid) {
        int count = 0;
        for(int  i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    adjustGrid(grid, i, j);
                    ++count;
                }
            }
        }
        
        return count;
    }
};

int main(){
    Solution sol;
    int ans = sol.numIslands({{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}});
    cout << ans <<endl;
    return 0;
}