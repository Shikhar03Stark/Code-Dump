#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
    vector<vector<int>> list(n, vector<int>(0));
    
    for(auto& edge: paths){
        list[edge[0]-1].push_back(edge[1]-1);
        list[edge[1]-1].push_back(edge[0]-1);
    }
    
    vector<int> flower(n, 1);
    
    unsigned int mask = 0b0;
    
    for(int node = 0; node<n; node++){
        for(auto& adj: list[node]){
            if(flower[node] == flower[adj] && (mask & (1<<adj)) > 0){
                flower[node]++;
            }
        }
        
        mask |= (1<<node);
    }
    
    return flower;

}

int main(){
    int node;
    cin>>node;
    vector<vector<int>> edges;
    {
        int from, to;
        do{
            cin >> from >> to;
            if(from != to){
                edges.push_back({from,to});
            }
        }while(from != to);
    }

    auto ans = gardenNoAdj(node, edges);

    for(auto& flower: ans){
        cout << flower << endl;
    }
    return 0;
}