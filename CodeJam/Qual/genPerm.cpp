#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

void genPerms(vector<vector<int>>& ans, vector<int>& state, int start, int n){
    if(start >= n){
        ans.push_back(state);
        return;
    }
    for(int i = start; i<n; i++){
        swap(state[i], state[start]);
        genPerms(ans, state, start+1, n);
        swap(state[i], state[start]);
    }  
}

int main(){
    vector<int> state = {1,2,3,4};
    vector<vector<int>> ans;
    genPerms(ans, state, 0, 4);
    cout << ans.size() << endl;
    for(auto& row: ans){
        cout << row.size() << endl;
        for(auto& e: row){
            cout << e << " ";
        }
        cout << endl;
    }
    return 0;
}