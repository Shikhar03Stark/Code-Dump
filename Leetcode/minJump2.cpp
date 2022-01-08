#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

class Solution {

public : 

        vector<int> memo;
    
    int solve(vector<int>& nums, int index){
        if(index == nums.size()-1){
            return 0;
        }
        if(memo[index] != -1){
            return memo[index];
        }
        int n = nums.size()-1;
        int minJ = 1000;
        if(index + nums[index] >= n){
            minJ = 1;
        }
        else{
            int minval = INT_MAX;
             for(int i = index+nums[index]; i>index; i--){
                minval = min(minval, solve(nums, i));
            }
            minJ = 1 + minval;
        }
        
        return memo[index] = minJ;
    }
    
    int jump(vector<int>& nums) {
        memo.resize(nums.size(),-1);
        return solve(nums, 0);
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,1,1,1};
    cout << sol.jump(nums) << endl;
    return 0;
}
