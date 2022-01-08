#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int

using namespace std;

class Solution {

public : 

    vector<int> movesToStamp(string stamp, string target) {
        vector<vector<char>> grid(target.size()-stamp.size()+1, vector<char>(target.size(), '0'));
        int rows = target.size() - stamp.size() + 1;
        int col = target.size();
        for(int i = 0; i<rows; i++){
            for(int k = 0; k<stamp.size(); k++){
                grid[i][i+k] = stamp[k];
            }
        }
        
        //set<int> ans;
        deque<int> ans;
        int r = 0;
        for(int i = 0; i<target.size(); i++){
            bool found = false;
            if(grid[r][i] == '0'){
                if(ans.empty()){
                    return {};
                }
                int start = ans.back();
                ans.pop_back();
                ans.push_front(start);
                r++;
            }
            while(r<rows){
                if(grid[r][i] == target[i]){
                    if(r != ans.back()){
                        ans.push_back(r);
                    }
                    found = true;
                    break;
                }
                ++r;
            }
            if(!found){
                return {};
            }
        }
        
        vector<int> res;
        while(!ans.empty()){
            res.push_back(ans.front());
            ans.pop_front();
        }
        
        return res;
    }
};

int main(){
    string target = "ababc";
    string stamp = "abc";
    Solution sol;
    vector<int> ans = sol.movesToStamp(stamp, target);
    for(auto& e : ans){
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
