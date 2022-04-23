// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void pre(){
    
    return;
}

void falldown(vector<string> &grid, int r, int c){
    int n = grid.size();
    for(int i = r; i<n; i++){
        if(i+1<n && grid[i+1][c] == '.'){
            grid[i][c] = '.';
            grid[i+1][c] = '*';
        }
        else{
            break;
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> grid(n, string(m, '.'));
    for(auto& e: grid){
        cin >> e;
    }

    for(int c = 0; c<m; c++){
        for(int r = n-1; r>=0; r--){
            if(grid[r][c] == '*'){
                falldown(grid, r, c);
            }
        }
    }

    for(auto& e: grid){
        cout << e << nl;
    }
    // cout << nl;

    return;
}

int main(){
    FASTIO
    pre();
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}