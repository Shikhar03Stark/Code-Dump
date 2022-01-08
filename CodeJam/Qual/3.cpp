#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

bool solve(vector<int>& state, int cost, int idx, bool rev, int n){
    if(cost==0 && idx==n-1)
        return true;
    if(cost < 0 || idx >= n-1){
        return false;
    }
    /*if(idx > (n-1)/2){
        return solve(state, cost-1, idx+1, rev, n);
    }*/

    for(int k = 0; k<n; k++){
        if(state[k]>=state[idx]){
            reverse(state.begin()+min(idx,k), state.begin() + max(idx,k)+1);
            bool found = solve(state, cost - (k-idx+1), idx+1, rev, n);
            if(found){
                return true;
            }
            reverse(state.begin()+min(idx,k), state.begin() + max(idx,k)+1);
        }
    }
    return false;
}

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

bool optimizedTree(vector<vector<int>>& ans, vector<int>& state, int start, int n, int c){
    if(start>=n){
        vector<int> arr(state);
        int cost = 0;
        for(int i = 0; i<n-1; i++){
            int minj = i;
            for(int j = i+1; j<n; j++){
                if(arr[minj] >= arr[j]){
                    minj = j;
                }
            }
            reverse(arr.begin()+i, arr.begin()+minj+1);
            cost += minj - i +1;
        }
        if(cost == c){
            ans.push_back(state);
            return true;
        }
        return false;
    }

    for(int i = start; i<n ;i++){
        swap(state[i], state[start]);
        bool found = optimizedTree(ans, state, start+1, n, c);
        if(found){
            return true;
        }
        swap(state[i], state[start]);
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    for(int z = 1; z<=t; z++){
        cout << "Case #" << z << ": ";
        int n, c;
        cin >> n >> c;
        if(c < n-1 || c > (n*(n+1)/2)-1){
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        
        vector<int> state(n,0);
        for(int i = 0; i<n; i++){
            state[i] = i+1;
        }
        vector<vector<int>> ans;
        //genPerms(ans, state, 0, n);
        bool found = optimizedTree(ans, state, 0, n, c);
        if(found){
            for(int i = 0; i<n; i++){
                cout << ans[0][i] << " ";
            }
            cout << endl;
        }
        else{
            cout << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}