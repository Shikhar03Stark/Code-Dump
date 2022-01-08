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
        int n;
        cin >>n;
        vector<vector<int>> mat(n, vector<int>(n));
        int nonz = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                cin >> mat[i][j];
                if(mat[i][j] != 0){
                    nonz++;
                }
            }
        }

        int k = 0;
        for(k=0; k<n; k++){
            if(nonz <= n*(2*k + 1) - k*(k+1)){
                break;
            }
        }
        cout << k << endl;
    }
    return 0;
}