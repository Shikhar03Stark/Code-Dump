#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

class Solution {

public : 

        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> path(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        path[m-1][n-1] = 1;
        for(int i = m-2; i>=0; i--){
            if(obstacleGrid[i][n-1] == 1){
                path[i][n-1] = 0;
                continue;
            }
            if(path[i+1][n-1] == 0){
                path[i][n-1] = 0;
            }
            else{
                path[i][n-1] = 1;
            }
        }
        
        for(int i = n-2; i>=0; i--){
            if(obstacleGrid[m-1][i] == 1){
                path[m-1][i] = 0;
                continue;
            }
            if(path[m-1][i+1] == 0){
                path[m-1][i] = 0;
            }
            else{
                path[m-1][i] = 1;
            }
        }
        
        for(int i = m-2; i>=0; i--){
            for(int j = n-2; j>=0; j--){
                if(obstacleGrid[i][j] == 1){
                    path[i][j] = 0;
                }
                else{
                    path[i][j] = path[i+1][j] + path[i][j+1];    
                }
            }
        }
        
        return path[0][0];
    }
};

int main(){
    Solution sol;
    vector<vector<int>> path = 
    {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };
    int uniq = sol.uniquePathsWithObstacles(path);
    cout << uniq << endl;

    return 0;
}
