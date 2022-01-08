#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int z = 1; z<=t; z++){
        cout << "Case #" << z << ": ";
        int n;
        cin >> n;
        vector<vector<int>> mat(2*n-1, vector<int>(n,0));
        for(auto& row: mat){
            for(auto& e : row){
                cin >> e;
            }
        }

        map<int, int> freq;

        stable_sort(mat.begin(), mat.end());

        for(auto& row: mat){
            for(auto& e : row){
                freq[e]++;
            }
        }
        vector<int> ans;
        for(auto& p: freq){
            if(p.second%2 == 1){
                ans.push_back(p.first);
            }
        }

        sort(ans.begin(), ans.end());

        for(int i = 0; i<n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}