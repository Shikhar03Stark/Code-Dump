#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int solve(vector<vector<int>>& stacks, vector<int>& ptr, int sum, int p){
    if(p<=0){
        return sum;
    }
    int mm=0;
    if(ptr[0]++ < stacks[0].size()){
        mm = solve(stacks, ptr, sum + stacks[0][ptr[0]-1], p-1);
        ptr[0]--;
    }
    for(int i = 1; i<stacks.size(); i++){
        if(ptr[i]++ < stacks[i].size()){
            mm = max(mm, solve(stacks, ptr, sum + stacks[i][ptr[i]-1], p-1));
            ptr[i]--;
        }
    }

    return mm;

}

int main(){
    int t;
    cin>>t;
    for(int z = 1; z<=t; z++){
        cout << "Case #" << z << ": ";
        int n, k, p;
        cin >> n >> k >> p;
        vector<vector<int>> stacks(n, vector<int>(k,0));
        for(int i = 0; i<n; i++){
            for(auto & p : stacks[i]){
                cin >> p;
            }
        }
        vector<int> ptr(n,0);
        cout << solve(stacks, ptr, 0, p) << endl;


    }
    return 0;
}