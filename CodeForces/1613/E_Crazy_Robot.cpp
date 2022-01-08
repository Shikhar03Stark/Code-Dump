// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int dir[] = {1,0,-1,0,1};
int m, n;

inline bool inside(int r, int c, int m, int n){
    if(r<0 || r>=m || c<0 || c>=n) return false;
    return true;
}

/*inline bool possible(vector<vector<char>> &grid, int r, int c){
    int free = 0;
    int pos = 0;
    if(grid[r][c] == '#') return false;
    int nr,nc;
    nr = r+1, nc = c+0;
    if(inside(nr, nc, m, n) && grid[nr][nc] != '#' ){
        free++;
        if(grid[nr][nc] == 'L' || grid[nr][nc] == '+'){
            pos++;
        }
    }
    nr = r-1, nc = c+0;
    if(inside(nr, nc, m, n) && grid[nr][nc] != '#' ){
        free++;
        if(grid[nr][nc] == 'L' || grid[nr][nc] == '+'){
            pos++;
        }
    }
    nr = r+0, nc = c+1;
    if(inside(nr, nc, m, n) && grid[nr][nc] != '#' ){
        free++;
        if(grid[nr][nc] == 'L' || grid[nr][nc] == '+'){
            pos++;
        }
    }
    nr = r+0, nc = c-1;
    if(inside(nr, nc, m, n) && grid[nr][nc] != '#' ){
        free++;
        if(grid[nr][nc] == 'L' || grid[nr][nc] == '+'){
            pos++;
        }
    }
    return free-pos<=1;
}*/

int solve(){
    m, n;
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n));
    int lr = 0, lc = 0;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'L') {
                lr = i;
                lc = j;
            }
        }
    }

    auto possible = [&](int r, int c)->bool{
        int free = 0;
        int pos = 0;
        if(grid[r][c] == '#') return false;
        int nr,nc;
        nr = r+1, nc = c+0;
        if(inside(nr, nc, m, n) && grid[nr][nc] != '#' ){
            free++;
            if(grid[nr][nc] == 'L' || grid[nr][nc] == '+'){
                pos++;
            }
        }
        nr = r-1, nc = c+0;
        if(inside(nr, nc, m, n) && grid[nr][nc] != '#' ){
            free++;
            if(grid[nr][nc] == 'L' || grid[nr][nc] == '+'){
                pos++;
            }
        }
        nr = r+0, nc = c+1;
        if(inside(nr, nc, m, n) && grid[nr][nc] != '#' ){
            free++;
            if(grid[nr][nc] == 'L' || grid[nr][nc] == '+'){
                pos++;
            }
        }
        nr = r+0, nc = c-1;
        if(inside(nr, nc, m, n) && grid[nr][nc] != '#' ){
            free++;
            if(grid[nr][nc] == 'L' || grid[nr][nc] == '+'){
                pos++;
            }
        }
        return free-pos<=1;
    };

    queue<pair<int,int>> Q;
    Q.push({lr,lc});
    vector<vector<bool>> vis(m, vector<bool>(n));
    vis[lr][lc] = true;
    while(!Q.empty()){
        auto p = Q.front(); Q.pop();
        int r = p.first, c = p.second;
        int nr,nc;
        nr = r+1, nc = c+0;
        if(inside(nr,nc, m,n) && possible(nr, nc) && !vis[nr][nc] ){
            Q.push({nr,nc});
            vis[nr][nc] = true;
            grid[nr][nc] = '+'; 
        }
        nr = r-1, nc = c+0;
        if(inside(nr,nc, m,n) && possible(nr, nc) && !vis[nr][nc] ){
            Q.push({nr,nc});
            vis[nr][nc] = true;
            grid[nr][nc] = '+'; 
        }
        nr = r+0, nc = c+1;
        if(inside(nr,nc, m,n) && possible(nr, nc) && !vis[nr][nc] ){
            Q.push({nr,nc});
            vis[nr][nc] = true;
            grid[nr][nc] = '+'; 
        }
        nr = r+0, nc = c-1;
        if(inside(nr,nc, m,n) && possible(nr, nc) && !vis[nr][nc] ){
            Q.push({nr,nc});
            vis[nr][nc] = true;
            grid[nr][nc] = '+'; 
        }
    }

    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cout << grid[i][j];
        }
        cout << nl;
    }

    return 0;
}

int main(){
    FASTIO
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}