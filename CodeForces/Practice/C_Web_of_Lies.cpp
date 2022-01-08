#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int dfs(vector<set<int>> &graph, int node, unordered_map<int,bool> &vis){
    if(vis[node] == true){
        return 0;
    }
    vis[node] = true;
    if(graph[node].size() == 0){
        return 0;
    }
    bool isVul = (node < *(begin(graph[node]))) ? true : false;
    if(isVul){
        set<int> adj = graph[node];
        graph[node].clear();
        for(auto next: adj){
            auto idx = graph[next].find(node);
            graph[next].erase(node);
        }
        int ans = 1;
        for(auto next: adj){
            if(vis[next] == false)
                ans += dfs(graph, next, vis);
        }
        return ans;
    }
    else{
        int ans = 0;
        for(auto next: graph[node]){
            if(vis[next] == false)
                ans += dfs(graph, next, vis);
        }
        return ans;
    }
}

int main(){
    int n, edges;
    cin >> n >> edges;
    vector<set<int>> gph(n+1);
    for(int i = 0; i<edges; i++){
        int u, v;
        cin >> u >> v;
        gph[u].insert(v);
        gph[v].insert(u);
    }
    int queries;
    cin >> queries;
    for(int q = 0; q<queries; q++){
        int type;
        cin >> type;
        if(type == 1){
            int u, v;
            cin >> u >> v;
            gph[u].insert(v);
            gph[v].insert(u);
        }
        else if(type == 2){
            int u, v;
            cin >> u >> v;
            //auto idx = gph[u].find(v);
            gph[u].erase(v);
            //idx = gph[v].find(u);
            gph[v].erase(u);
        }
        else{
            vector<set<int>> graph = gph;
            int ans = 0;
            for(int i = 1; i<=n; i++){
                unordered_map<int,bool> vis;
                //if(vis[i] == false)
                    ans += dfs(graph, i, vis);
            }
            cout << n-ans << endl;
        }
    }
    return 0;
}