#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

vector<vector<int>> vis(500, vector<int>(500, -1));
int n;
bool put(vector<vector<int>>& grid, int x, int row, int col, int count){
    if( col > row || row >= n || col >= n || row < 0 || col < 0 || vis[row][col] != -1){
        return false;
    }
    if(count <= 1){
        grid[row][col] = x;
        vis[row][col] = x;
        return true;
    }
    //donw
    if(put(grid, x, row+1, col, count-1)){
        grid[row][col] = x;
        vis[row][col] = x;
        return true;
    }
    //left
    if(put(grid, x, row, col-1, count-1)){
        grid[row][col] = x;
        vis[row][col] = x;
        return true;
    }
    //donw
    if(put(grid, x, row-1, col, count-1)){
        grid[row][col] = x;
        vis[row][col] = x;
        return true;
    }
    //left
    if(put(grid, x, row, col+1, count-1)){
        grid[row][col] = x;
        vis[row][col] = x;
        return true;
    }

    return false;

}


int main(){
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n,0));
    for(int i = 0; i<n; i++){
        cin >> grid[i][i];
    }
    bool possible = true;
    for(int i = n-1; i>=0; i--){
        if(put(grid, grid[i][i], i, i, grid[i][i]) == false){
            possible = false;
            break;
        }
    }

    if(!possible){
        cout << -1 << endl;
    }
    else{
        for(int i = 0; i<n; i++){
            for(int j=0; j<=i; j++){
                cout << grid[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}