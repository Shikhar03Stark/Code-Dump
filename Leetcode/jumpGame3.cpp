#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

class Solution {

public : 
    unordered_map<int, bool> memo;
    unordered_map<int, bool> visited;
    bool canReach(vector<int>& arr, int start) {
            if(visited.count(start) > 0){
                if(visited[start]){
                    return false;
                }
            }
            visited[start] = true;
            if(memo.count(start) > 0){
                return memo[start];
            }
            if(arr[start] == 0){
                return true;
            }
            else{
                bool ahead = false, behind = false;
                if(start + arr[start] < arr.size()){
                    ahead = canReach(arr, start + arr[start]);
                }
                if(start - arr[start] >= 0){
                    behind = canReach(arr, start - arr[start]);
                }

                return memo[start] = ahead || behind;
            }
    }
};
