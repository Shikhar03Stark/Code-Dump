#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

class Solution {

public : 

        vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto& e : edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        set<int> vis;
        queue<int> Q;
        for(int i = 0; i<n; i++){
            if(graph[i].size() <= 1){
                Q.push(i);
                vis.insert(i);
            }
        }
        while(n>2){
            int size = Q.size();
            n -= size;
            for(int i = 0; i<size; i++){
                int top = Q.front();
                Q.pop();
                for(auto& adj : graph[top]){
                    if(vis.find(adj) == vis.end()){
                        Q.push(adj);
                        vis.insert(adj);
                    }
                }
            }
        }
        
        vector<int> roots;
        while(!Q.empty()){
            roots.push_back(Q.front());
            Q.pop();
        }
        return roots;
    }
};

int main(){
    vector<vector<int>> edges = {
        {3,0},
        {3,1},
        {3,2},
        {3,4},
        {4,5}
    };
    Solution sol;
    sol.findMinHeightTrees(6, edges);
    return 0;
}
