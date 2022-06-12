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

void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(auto& s: grid){
        cin >> s;
    }
    int left = m, right = 1, top = n, bottom = 1;
    for(int i = 0; i<n; i++){   
        for(int j = 0; j<m; j++){
            if(grid[i][j] == 'B'){
                left = min(left, j+1);
                right = max(right, j+1);

                top = min(top, i+1);
                bottom = max(bottom, i+1);
            }
        }
    }
    int col = 1;
    for(int i = 1; i<=m; i++){
        if(max(abs(col-left), abs(col-right)) > max(abs(i-left), abs(i-right))){
            col = i;
        }
    }
    int row = 1;
    for(int i = 1; i<=n; i++){
        if(max(abs(row-bottom), abs(row-top)) > max(abs(i-bottom), abs(i-top))){
            row = i;
        }
    }
    
    cout << row << " " << col << nl;
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