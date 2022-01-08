// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m, 0));
    for(auto& row: grid){
        for(auto& e: row){
            cin >> e;
        }
    }
    vector<int> crow(n, m), ccol(m, n);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] == '*'){
                crow[i]--;
                ccol[j]--;
            }
        }
    }
    int minrow = min_element(crow.begin(), crow.end()) - crow.begin();
    int mincol = min_element(ccol.begin(), ccol.end()) - ccol.begin();
    int ans = INT_MAX;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(crow[i] == 0 || ccol[j] == 0){
                ans = min(ans, max(crow[i], ccol[j]));
            }
            else{
                ans = min(ans, crow[i]+ccol[j] - (grid[i][j]=='.'?1:0));
            }
        }
    }
    cout << ans << endl;
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