// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    int n, m, r, c;
    cin >> n >> m >> r >>c;
    vector<string> grid(n);
    bool hasB = false;
    for(int i = 0; i<n; i++){
        string s;
        cin >> s;
        grid[i] = s;
        for(int j = 0; j<m; j++){
            if(s[j] == 'B'){
                hasB = true;
                break;
            }
        }
    }

    if(!hasB){
        cout << -1 << nl;
        return;
    }

    r--;
    c--;

    if(grid[r][c] == 'B') {
        cout << 0 << nl;
        return;
    }

    bool inlin = false;
    for(int i = 0; i<n; i++){
        if(grid[i][c] == 'B'){
            cout << 1 << nl;
            return;
        }
    }

    for(int i = 0; i<m; i++){
        if(grid[r][i] == 'B'){
            cout << 1 << nl;
            return;
        }
    }

    cout << 2 << nl;

    return;
}

int main(){
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}