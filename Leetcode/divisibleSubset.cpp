#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

class Solution {

public : 
    
    void solve(vector<int> &nums, int idx, vector<int> &dp, vector<int> prev){
        int n = nums.size();
        if(idx >= n){
            return;
        }
        for(int i = 0; i<idx; i++){
            if(nums[idx]%nums[i] == 0){
                if(dp[idx] < dp[i]+1){
                    dp[idx] = dp[i] + 1;
                    prev[idx] = i;
                }
            }
        }
        solve(nums, idx+1, dp, prev);
    }
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        vector<int> dp(n, 1), prev(n,-1);
        solve(nums, 0, dp, prev);
        int curr = max_element(begin(dp), end(dp)) - begin(dp);
        for(auto &e: dp){
            cout << e << " ";
        }
        cout << endl;
        for(auto &e: prev){
            cout << e << " ";
        }
        cout << endl;
        vector<int> ans;
        while(curr >= 0){
            ans.push_back(nums[curr]);
            curr = prev[curr];
        }
        
        if(ans.size() == 0){
            return {nums[0]};
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,3,6,8,14};
    auto ans = sol.largestDivisibleSubset(nums);
    for(auto &e: ans){
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
