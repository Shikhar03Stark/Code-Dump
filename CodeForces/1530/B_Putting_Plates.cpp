#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int h,b;
vector<vector<int>> vis;
bool inBound(int y, int x){
    if(x>=b || x < 0 || y>=h || y < 0)
        return false;
    return true;
}
void dfs(vector<vector<int>>& table, int x, int y){
    if(x>=b || x < 0 || y >= h || y< 0){
        return;
    }
    if(vis[y][x] == 0){
        vis[y][x] = 1;
        if(x == 0 || y == 0 || x == b-1 || y == h-1){
            //edge
            if(table[y][x] != 2){
                table[y][x] = 1;
                if(inBound(y+1, x))   table[y+1][x] = 2;
                if(inBound(y+1, x+1)) table[y+1][x+1] = 2;
                if(inBound(y,   x+1)) table[y][x+1] = 2;
                if(inBound(y-1, x+1)) table[y-1][x+1] = 2;
                if(inBound(y-1, x))   table[y-1][x] = 2;
                if(inBound(y-1, x-1)) table[y-1][x-1] = 2;
                if(inBound(y,   x-1)) table[y][x-1] = 2;
                if(inBound(y+1, x-1)) table[y+1][x-1] = 2;
            }
        }

        dfs(table, y, x+1);
        dfs(table, y+1, x);
        dfs(table, y, x-1);
        dfs(table, y-1, x);
    }

}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin >> h >> b;
        vector<vector<int>> table(h, vector<int>(b, 0));
        /*vis.resize(h, vector<int>(b, 0));
            dfs(table, 0, 0);
        for(int i = 0; i<h; i++){
            for(int j = 0; j<b; j++){
                if(table[i][j] == 2){
                    table[i][j] = 0;
                }
            }
        }
        vis.clear();*/
        for(int i = 0; i<h; i+=h-1){
            for(int j = 0; j<b; j+=2){
                table[i][j] = 1;
            }
        }

        for(int j = 2; j<h; j += 2){
            if(j!=0 && j!=1 && j!=h-1 && j!=h-2){
                table[j][0] = 1;
                table[j][b-1] = 1;
            }
        }
        for(auto& row: table){
            for(auto& e: row){
                cout << e;
            }
            cout << endl;
        }
        cout << endl;

    }
    return 0;
}