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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> paths(n, vector<int>(m, 0));
        for(auto& check: paths){
            for(auto& path: check){
                cin >> path;
            }
        }

        vector<int> res(m,INT_MAX);
        bool asc = true;
        for(int i = 0; i<n; i++){
            if(asc){
                sort(paths[i].begin(), paths[i].end());
            }
            else{
                sort(paths[i].begin(), paths[i].end(), greater<int>());
            }
            for(int j = 0; j<m; j++){
                cout << paths[i][j] << " ";
            }
            cout << "\n";
            asc = !asc;
        }
    }
    return 0;
}