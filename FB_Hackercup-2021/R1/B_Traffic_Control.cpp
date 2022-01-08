#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int z = 1; z<=t; z++){
        cout << "Case #" << z << ": ";
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        vector<vector<int>> grid(n, vector<int>(m, 0));
        for(int i = 0; i<n-1; i++){
            for(int j = 1; j<m-1; j++){
                grid[i][j] = 1000;
            }
        }

        if( a < m+n-1 || b < m+n-1){
            cout << "Impossible" << endl;
            continue;
        }

        int q_a = a/(m+n-1);
        int q_b = b/(m+n-1);
        if(q_a<=q_b){
            for(int i = 0; i<n; i++){
                grid[i][0] = q_a;
            }
            for(int i = 0; i<m; i++){
                grid[n-1][i] = q_a;
            }
            grid[0][0] += a%(m+n-1);

            int res = q_a*m;
            int b_res = b - res;
            int b_mean = b_res/(n-1);
            for(int i = 0; i<n-1;i++){
                grid[i][m-1] = b_mean;
            }
            grid[0][m-1] += b_res%(n-1);
        }
        else{
            for(int i = 0; i<n; i++){
                grid[i][m-1] = q_b;
            }
            for(int i = 0; i<m; i++){
                grid[n-1][i] = q_b;
            }
            grid[0][m-1] += b%(m+n-1);

            int res = q_b*m;
            int a_res = a - res;
            int a_mean = a_res/(n-1);
            for(int i = 0; i<n-1;i++){
                grid[i][0] = a_mean;
            }
            grid[0][0] += a_res%(n-1);
        }

        cout << "Possible" << endl;
        for(auto &row: grid){
            for(auto& e: row){
                cout << e << " ";
            }
            cout << endl;
        }
    }
    return 0;
}