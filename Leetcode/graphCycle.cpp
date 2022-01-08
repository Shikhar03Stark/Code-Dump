#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

class Solution {

public : 

    map<pair<int,int>, char> vis;
    
    bool dfs(vector<vector<char>>& grid, int i, int j){
        stack<pair<pair<int,int>, pair<int,int>>> S;
        S.push({{i,j}, {i,j}});
        int m = grid.size();
        int n = grid[0].size();
        while(!S.empty()){
            auto p = S.top(); S.pop();
            auto coord = p.first;
            auto last = p.second;
            vis[coord] = grid[coord.first][coord.second];
            vector<int> dir = {0,1,0,-1,0};
            for(int k = 0; k<dir.size()-1;k++){
                int nx = coord.second + dir[k+1];
                int ny = coord.first + dir[k];
                pair<int,int> pp = {ny, nx};
                //pair<int,int> l = {ny-i, nx-j}
                if(ny < m && nx < n && ny >= 0 && nx >= 0 && pp != last){
                    if(grid[ny][nx] == vis[coord]){
                        if(vis.count({ny,nx}) == 0){
                            S.push({{ny,nx}, coord});
                        }
                        else{
                            return true;
                        }
                    }
                }
            }
        }
        
        return false;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        bool hasCycle = false;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(vis.count({i,j}) == 0){
                    hasCycle = dfs(grid, i, j);
                }
                if(hasCycle){
                    return true;
                }
            }
        }
        
        return false;
    }
};

int main(){
    vector<vector<char>> grid = 
    {
        {'a','b','b'},
        {'b','z','b'},
        {'b','b','a'}
    };
    Solution sol;
    cout << sol.containsCycle(grid) << endl;
    return 0;
}
