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
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<ull>> grid(n, vector<ull>(m,0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cin >> grid[i][j];
                //grid[i][j] -= k;
            }
        }

        vector<vector<ull>> prefix(n+1, vector<ull>(m+1,0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                prefix[i+1][j+1] = grid[i][j] + prefix[i][j+1] + prefix[i+1][j] - prefix[i][j];
            }
        }

        vector<vector<ull>> sqSum(n, vector<ull>(m,0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                int order = min(n-i, m-j);
                //submat (i,j), (i+order,j), (i, j+order), (i+order, j+order)
                sqSum[i][j] = (prefix[i+order][j+order]/(order*order)) - (prefix[i][j+order]/(order*order)) - (prefix[i+order][j]/(order*order)) + (prefix[i][j]/(order*order));

            }
        }



        int maxSquare = min(m,n);
        int cnt = 0;
        for(int i = 0; i<n; i++){
            int idx = lower_bound(sqSum[i].begin(), sqSum[i].end(), k) - sqSum[i].begin();
            if(idx != m){
                for(int j = idx; j<m; j++){
                    int order = min(n-i,m-j);
                    for(int k = 1; k<=order; k++){
                        ll sum = (prefix[i+k][j+k]/(k*k)) - (prefix[i][j+k]/(k*k)) - (prefix[i+k][j]/(k*k)) + (prefix[i][j]/(k*k));
                        if(sum >= k)
                            cnt++;
                    }
                }
            }
        }
        /*
        for(int size = 1; size<=maxSquare; size++){
            for(int i = 0; i+size<=n; i++){
                for(int j = 0; j+size<=m; j++){
                    ll sum = prefix[i+size][j+size] - prefix[i][j+size] - prefix[i+size][j] + prefix[i][j];
                    if(sum >= 0){
                        cnt++;
                    }
                }
            }
        }*/

        cout << cnt << endl;
    }
    return 0;
}