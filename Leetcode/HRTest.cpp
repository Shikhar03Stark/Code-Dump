#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int numOfMoves(vector<int>& nums){
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int mi = 0;
    for(int i = 0; i<n; i++){
        if(nums[mi] >= nums[i]){
            mi = i;
        }
    }
    int nextSmall = mi+1;
    long count = 0;
    if(nextSmall >= n){
        return count;
    }
    else{
        while(nextSmall < n){
            if(nums[mi] == nums[nextSmall]){
                ++nextSmall;
                continue;
            }
            int diff = nums[nextSmall] - nums[mi];
            count += diff;
            nums[nextSmall] -= diff;
            mi = nextSmall;
            ++nextSmall;
        }

    }

    return count;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto& e: nums){
        cin >> e;
    }
    cout << numOfMoves(nums) << endl;
    return 0;
}