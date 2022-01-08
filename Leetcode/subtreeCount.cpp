#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

class Solution {

public : 

        unordered_map<char, int> charcount;
    void solve(vector<vector<int>>& list, vector<int>& ans, int node, string labels, unordered_map<int,bool> h){
        for(auto& child: list[node]){
            if(!h[child]){
                h[child] = true;
                solve(list, ans, child, labels, h);
                charcount[labels[child]]++;
            }
        }
        ans[node] = charcount[labels[node]]+1;
        for(auto& c : labels){
            cerr << c << " : " << charcount[c] << " : " << node << endl;
        }
    }
    
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> ans(n);
        vector<vector<int>> list(n);
        for(auto& e : edges){
            list[e[0]].push_back(e[1]);
            list[e[1]].push_back(e[0]);
        }
        unordered_map<int,bool> h;
        h[0] = true;
        solve(list, ans, 0, labels, h);
        
        return ans;

        parti
    }
};

int main(){
    Solution s;
    vector<vector<int>> edges = {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
    string labels = "abaedcd";
    s.countSubTrees(7, edges, labels);
    return 0;
}
