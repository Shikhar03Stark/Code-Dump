#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

class Solution {

public : 
    
    int dp[101][101];
    int takeIn(vector<pair<int,int>>& counts, int zeros, int ones, int idx){
        if(zeros < 0 || ones < 0)
            return 0;
        if(idx >= counts.size())
            return 0;
        
        if(dp[zeros][ones] != -1)
            return dp[zeros][ones];
    
        return dp[zeros][ones] = max(1+takeIn(counts, zeros-counts[idx].first, ones-counts[idx].second, idx+1),
                                     takeIn(counts, zeros, ones, idx+1));
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<pair<int,int>> counts(strs.size(), {0,0});
        for(int i = 0; i<=m; i++){
            for(int j = 0; j<=n; j++){
                dp[i][j] = -1;
            }
        }
        for(int i = 0; i<strs.size(); i++){
            for(int j = 0; j<strs[i].size(); j++){
                if(strs[i][j] == '0')
                    counts[i].first++;
                else
                    counts[i].second++;
            }
        }
        
       return takeIn(counts, m, n, 0);
        //return ;
    }
};

int main(){
    Solution sol;
    vector<string> arr = {"10", "0001", "111001", "1", "0"};
    cout << sol.findMaxForm(arr, 5, 3) << endl;
    return 0;
}
