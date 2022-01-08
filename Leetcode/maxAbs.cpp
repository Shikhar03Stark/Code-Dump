#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

class Solution {

public : 

        int maxAbsoluteSum(vector<int>& nums) {
        
        vector<int> aux(nums.size(), nums[0]);
        int max = INT_MIN;
        for(int i = 1; i<aux.size(); i++){
            int res = aux[i-1] + nums[i];
            if(abs(res) > abs(nums[i])){
                aux[i] = res;
            }
            else{
                aux[i] = nums[i];
            }
        }
        
        for(auto& e: aux){
            max = std::max(max, abs(e));
        }
        
        return max;
        
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,-5,1,-4,3,2};
    sol.maxAbsoluteSum(nums);

    return 0;
}
