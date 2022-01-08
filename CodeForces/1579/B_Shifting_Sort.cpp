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
        cin >> n;
        vector<int> arr(n);
        for(auto& e: arr){
            cin >> e;
        }
        vector<vector<int>> ans;
        for(int i = 0; i<n; i++){
            int mini = min_element(arr.begin()+i, arr.end()) - arr.begin();
            if(mini != i){
                int l = mini - i;
                rotate(arr.begin()+i, arr.begin()+mini, arr.end());
                vector<int> op = {i+1,n,l};
                ans.push_back(op);
            }
        }

        cout << ans.size() << endl;
        for(auto& ops: ans){
            cout << ops[0] << ' ' << ops[1] << ' ' << ops[2] << endl;
        }
    }
    return 0;
}