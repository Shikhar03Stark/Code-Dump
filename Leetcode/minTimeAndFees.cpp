#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<pair<int,int>>> graph(n);
        for(auto &edge: edges){
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        
        //{cost, fees, node}
        auto comp = [](const vector<int>& a, const vector<int>& b){
            if(a[0] < b[0]){
                return true;
            }
            else if(a[0] == b[0]){
                if(a[1] <= b[1]){
                    return true;
                }
                return false;
            }
            else{
                return false;
            }
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
        vector<int> new_node = {0, passingFees[0], 0};
        pq.push(new_node);
        
        int ans = INT_MAX;
        
        while(!pq.empty()){
            int size = pq.size();
            
            for(int i = 0; i<size; i++){
                vector<int> curr = pq.top(); pq.pop();
                int node = curr[2];
                int cost = curr[0];
                int fees = curr[1];
                
                for(auto& adj: graph[node]){
                    int nnode = adj.first;
                    int w = adj.second;
                    if(dist[nnode] > dist[node] + w){
                        dist[nnode] = dist[node]+w;
                        int new_fees = fees + passingFees[nnode];
                        if(nnode == n-1 && dist[nnode] <= maxTime){
                            ans = min(ans, new_fees);
                        }
                        vector<int> new_vec = {dist[nnode], new_fees, nnode};
                        pq.push(new_vec);
                    }
                }
            }
        }
        
        return ans;
    }
};

int main(){
    vector<vector<int>> edges = {
        {0,1,10},
        {1,2,10},
        {2,5,10},
        {0,3,1},
        {3,4,10},
        {4,5,15}
    };

    vector<int> minDist = {5, 1, 2, 20, 20, 3};
    Solution sol;
    int ans = sol.minCost(30, edges, minDist);
    cout << ans << endl;
    return 0;
}