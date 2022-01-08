#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

class Solution {

public : 

    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        for(int i = 0; i<n; i++){
            int j = i-1;
            for(;j>=0;j--){
                if(height[j] >= height[i]){
                    break;
                }
            }
            left[i] = max((height[j]<height[i])?j+1:i, 0);
            j = i+1;
            for(;j<n;j++){
                if(height[j] >= height[i]){
                    break;
                }
            }
            right[i] = min((height[j]<height[i])?j-1:i,n-1);
        }
        
        unordered_map<int,bool> filled;
        int water = 0;
        for(int i = 0; i<n ;){
            int start = left[i], end = right[i];
            filled[i] = true;
            int h = height[i];
            for(int j = start; j<=end; j++){
                if(filled.count(j) > 0)
                    continue;
                water += max(0, h - height[j]);
                filled[j] = true;
            }
            i = end+1;
        }
        
        return water;
    }
};


int main(){
    Solution sol;
    vector<int> water = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << sol.trap(water) << endl;
    return 0;
}