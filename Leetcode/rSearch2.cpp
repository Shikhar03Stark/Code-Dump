#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

class Solution {

public : 

    bool search(vector<int> nums, int target) {
        int low = 0, high = nums.size()-1;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                return true;
            }
            
            if(nums[low] < nums[mid]){
                if(target >= nums[low] && target <= nums[mid]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            else if(nums[mid] < nums[high]){
                if(target >= nums[mid] && target <= nums[high]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
            else{
                if(nums[low] == nums[mid]) ++low;
                if(nums[high] == nums[mid]) --high;
            }
            
        }
        
        return false;
    }
};

int main(){
    Solution sol;
    sol.search({2, 5, 6, 0, 0, 1, 2}, 3);

    return 0;
}