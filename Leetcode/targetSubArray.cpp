#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

class Solution {

public : 

        bool good(int len, vector<unsigned long>& prefix, int target){
        if(prefix[len-1]>=target){
            return true;
        }
        int start = 0, end = len;
        while(end<prefix.size()){
            if(prefix[end] - prefix[start] >= target){
                return true;
            }
            start++;
            end++;
        }
        
        return false;
    }
    
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<unsigned long> prefix(nums.size(), nums[0]);
        for(int i = 1; i<nums.size() ;i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
        
        int start = 1, end = nums.size(), mid;
        
        while(start<=end){
            mid = start + (end-start)/2;
            if(good(mid, prefix, target)){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        if(start == nums.size()){
            if(prefix[start] >= target){
                return true;
            }
            else{
                return false;
            }
        }
        return start;
        
    }
};


int main(){
    Solution sol;
    vector<int> arr = {1,1,1,1,1,1,1};
    sol.minSubArrayLen(11, arr);

    return 0;
}