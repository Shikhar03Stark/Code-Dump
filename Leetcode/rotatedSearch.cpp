#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums, int target, int low, int high){
    if(low>high){
        return -1;
    }
    else{
        int mid = low + (high - low)/2;
        if (nums[mid] == 0){
            return mid;
        }
        
        //if left half is sorted
        if(nums[low] < nums[mid]){
            if(target >= nums[low] && target <= nums[mid]){
                //simple BS
                return solve(nums, target, low, mid);
            }
            else{
                return solve(nums, target, mid+1, high);
            }
        }
        //right half is sorted
        else{
            if(target <= nums[high] && target >= nums[mid+1]){
                //simple BS
                return solve(nums, target, mid+1, high);
            }
            else{
                return solve(nums, target, low, mid);
            }
        }
    }
    
}

int search(vector<int>& nums, int target) {
    
    int ans = solve(nums, target, 0, nums.size()-1);
    
    return ans;
}

int main(){
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for(auto& e: nums){
        cin >> e;
    }
    cout << search(nums, target) << endl;
}