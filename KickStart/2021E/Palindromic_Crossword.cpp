#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

void constructGrid(vector<vector<char>> &grid, int r, int c, int &cnt){
    //check horizontal;
    int row = grid.size(), col = grid[0].size();
    int left = c, right = c;
    while(left >= 0 && grid[r][left] != '#'){
        left--;
    }
    while(right < col && grid[r][right] != '#'){
        right++;
    }
    left++;
    right--;
    int posc = right+left-c;
    if(grid[r][posc] == '.'){
        grid[r][posc] = grid[r][c];
        cnt++;
        constructGrid(grid, r, posc, cnt);
    }

    //check vertical
    int up = r, down = r;
    while(up >= 0 && grid[up][c] != '#'){
        up--;
    }
    while(down < row && grid[down][c] != '#'){
        down++;
    }
    up++;
    down--;
    int posr = up+down-r;
    if(grid[posr][c] == '.'){
        grid[posr][c] = grid[r][c];
        cnt++;
        constructGrid(grid, posr, c, cnt);
    }
}

int main(){
    int t;
    cin>>t;
    for(int z = 1; z<=t; z++){
        cout << "Case #" << z << ": ";
        int row, col;
        cin >> row >> col;
        vector<vector<char>> grid(row, vector<char>(col, '.'));
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                cin >> grid[i][j];
            }
        }

        int cnt = 0;
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(grid[i][j] >= 'A' && grid[i][j] <= 'Z'){
                    constructGrid(grid, i, j, cnt);
                }
            }
        }


        cout << cnt << endl;
        for(auto & row: grid){
            for(auto &c: row){
                cout << c;
            }
            cout << endl;
        }

    }
    return 0;
}