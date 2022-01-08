#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

class Solution {

public : 
    void genDP(vector<int> &nums, vector<int> &dp, int index){
        if(index < 0)
            return;
        if(nums[index] == 0){
            genDP(nums, dp, index-1);
            return;
        }
        //straight jump
        if(nums.size() - index - 1 <= nums[index]){
            dp[index] = 1;
            genDP(nums, dp, index-1);
            return;
        }

        //right side
        int minn = INT_MAX;
        for(int i = index+1; i<=nums[index]+index && i < nums.size(); i++){
            if(minn > dp[i]){
                minn = dp[i];
            }
        }
        dp[index] = minn == INT_MAX ? INT_MAX : minn+1;
        genDP(nums, dp, index-1);
    }

    int jump(vector<int>& nums) {
        int position = nums.size() - 1;
	    int steps = 0;
	    while (position != 0) {
		    for (int i = 0; i < position; i++) {
			    if (nums[i] >= position - i) {
			    	position = i;
			    	steps++;
			    	break;
			    }
		    }
	    }
	    return steps;
        }
};

int main(){

    Solution sol;
    vector<int> vec = {2,3,1,1,4};
    int ans = sol.jump(vec);
}
