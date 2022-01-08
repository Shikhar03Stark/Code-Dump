#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            char c;
            cin >> c;
            if(c == '*')
                grid[i][j] = 1;
            else
                grid[i][j] = 0;
        }
    }
    vector<vector<int>> prefix(n+1, vector<int>(n+1, 0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            prefix[i+1][j+1] = prefix[i+1][j] + prefix[i][j+1] - prefix[i][j] + grid[i][j];
        }
    }
    /*for(auto& row: prefix){
        for(auto& e: row){
            cerr << e << " ";
        }
        cerr << endl;
    }*/
    for(int t = 0; t<q; t++){
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        ll ans = prefix[y2][x2] - prefix[y1-1][x2] - prefix[y2][x1-1] + prefix[y1-1][x1-1];
        cout << ans << endl;
    }
    return 0;
}