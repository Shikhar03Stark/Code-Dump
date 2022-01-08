#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr, int n, vector<int>& memo){
    if(memo[n] != -1){
        return memo[n];
    }
    
    int l_max = 0;
    for(int i = n-1; i>=0; i--){
        int ans = solve(arr, i, memo);
        if(arr[i] < arr[n]){
            if(l_max < ans){
                l_max = ans;
            }
        }
    }
    
    return memo[n] = 1+l_max;
}

int lengthOfLIS(vector<int>& nums) {
    vector<int> memo(nums.size(),-1);
    int lis = solve(nums, nums.size()-1, memo);
    int ans = 1;
    for(int i = 0; i<memo.size(); i++){
        if(ans < memo[i]){
            ans = memo[i];
        }
    }
    return ans;
}

int main(){
    int size;
    cin >> size;
    vector<int> arr(size);
    for(auto& e: arr){
        cin >> e;
    }

    cout << lengthOfLIS(arr) << endl;

    return 0;
}