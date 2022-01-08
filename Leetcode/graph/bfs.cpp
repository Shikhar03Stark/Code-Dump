#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

vector<int> bfs(vector<int> g[], int N);

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, e;
        cin >> n >> e;
        vector<int> g[n];

        for(int i = 0; i<e;i++){
            int from, to;
            cin >> from >> to;
            g[from].push_back(to);
        }
        auto res = bfs(g, n);
        for(auto node: res){
            cout << node << " ";
        }
        cout << endl;
    }
    return 0;
}



vector <int> bfs(vector<int> g[], int N) {

    queue<int> q;
    q.push(0);
    vector<int> ans;
    unordered_map<int, bool> vis;
    while(!q.empty()){
        int node = q.front();
        ans.push_back(node);
        q.pop();
        vis[node] = true;
        for(int i = 0; i<g[node].size(); i++){
            if(vis.count(g[node][i]) == 0){
                q.push(g[node][i]);
            }
        }
    }
    
    return ans;
}