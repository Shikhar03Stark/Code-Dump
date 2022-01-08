#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int r, c;
vector<vector<ll>> grid;

bool isValid(int i, int j){
    if(i<0 || j <0 || i >=r || j>=c)
        return false;
    return true;
}

bool goodBox(int i, int j){
    int dir[] = {0,1,0,-1,0};
    bool ans = true;
    for(int k = 1; k<4; k++){
        int y = i + dir[k-1], x = j + dir[k];
        ans = ans&&(!isValid(y,x) || abs(grid[i][j] - grid[y][x]) <2);
    }

    return ans;
}

int boxAdded(int i, int j, ll box){
    if(!isValid(i,j)){
        return 0;
    }
    if(goodBox(i,j)){
        return 0;
    }
    else{
        int ans = 0;
        int dir[] = {0,1,0,-1,0};
        for(int k = 1;k<5; k++){
            int y = i + dir[k-1], x = j + dir[k];
            if(isValid(y,x)){
                if(box > grid[y][x]){
                    ans += box - grid[y][x] -1;
                    grid[y][x] += box - grid[y][x] -1;
                    ans += boxAdded(y,x, grid[y][x]);
                }
            }
        }

        return ans;
    }
}

int main(){
    int t;
    cin>>t;
    for(int z = 1; z<=t; z++){
        cout << "Case #" << z << ": ";
        cin >> r >> c;
        grid.resize(r);
        for(auto& r: grid){
            r.resize(c);
        }
        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                cin >> grid[i][j];
            }
        }
        ll ans = 0;
        for(int i = 0; i<r; i++){
            for(int j =0; j<c; j++){
                ans += boxAdded(i,j, grid[i][j]);
            }
        }
        cout << ans << endl;

    }
    return 0;
}