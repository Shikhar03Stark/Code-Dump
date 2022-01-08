#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, d;
        cin >> n >> m >> d;
        vector<vector<char>> grid(n, vector<char>(m, '.'));
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cin >> grid[i][j];
            }
        }

        for(int i = n-1; i>=0; i--){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == '*'){
                    int k = 0;
                    while(i-k>=0 && j-k >= 0 && j+k < m){
                        if(grid[i-k][j-k] == '*' && grid[i-k][j+k] == '*'){
                            k++;
                        }
                        else{
                            break;
                        }
                    }
                    if(k-1 >= d){
                        //mark vis
                        for(int t = 0; t<k; t++){
                            vis[i-t][j-t] = vis[i-t][j+t] = true;
                        }
                    }
                }
            }
        }

        bool  poss = true;
        for(int i = 0; i<n && poss; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == '*'){
                    if(vis[i][j]);
                    else{
                        poss = false;
                        break;
                    }
                }
            }
        }

        cout << (poss?"YES":"NO") << endl;


    }
    return 0;
}