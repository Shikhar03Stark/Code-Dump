#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

class Solution {

public : 

        int countPairs(vector<int>& nums, int low, int high) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<pair<int,int>> ranges(n);
        for(int i = 0; i<n; i++){
            ranges[i] = {low^nums[i], high^nums[i]};
        }
        
        int count = 0;
        for(auto& range: ranges){
            int l = lower_bound(nums.begin(), nums.end(), range.first) - nums.begin();
            int u = lower_bound(nums.begin(), nums.end(), range.second) - nums.begin();
            if(l < n && u < n){
                count += max(0,abs(l-u)+1);
                if(nums[l] == range.first){
                    count++;
                }
                if(nums[u] == range.second){
                    count++;
                }
            }
        }
        
        return count;
    }
};

int main(){
    Solution sol;
    vector<int> arr = {1,4,2,7};
    cout << sol.countPairs(arr, 2,6) << endl;
    return 0;
}
