#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

class Solution {

public : 

    int minimumSize(vector<int>& nums, int maxOperations) {
        priority_queue<int> pq;
        for(auto &e: nums){
            pq.push(e);
        }
        
        int trial = 0;
        while(maxOperations){
            int top = pq.top();
            pq.pop();
            if(pq.empty()){
                int first;
                if(maxOperations!=1){
                     first = log(top)/log(maxOperations);
                }
                else{
                    first = top/2;
                }
                pq.push(first);
                pq.push(top-first);
            }
            else{
                int first;
                stack<int> S;
                while(!pq.empty() && (pq.top() == top)){
                    S.push(pq.top());
                    pq.pop();
                }
                if(pq.empty()){
                    first = top/2;
                }
                else{
                    first = pq.top();
                }
                while(!S.empty()){
                    pq.push(S.top());
                    S.pop();
                }
                pq.push(first);
                pq.push(top-first);
            }
            maxOperations--;
        }
        
        return pq.top();
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,4,8,4};
     int ans = sol.minimumSize(nums, 4);
    return 0;
}
