#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

void dfs(vector<vector<int>> &gph, vector<int> &vis, int curr, int parent){
    if(vis[curr] == -1){
        int adj_color = -1;

        for(int i = 0; i<gph.size(); i++){
            bool found = true;
            for(auto& adj: gph[curr]){
                if(vis[adj] == i){
                    found = false;
                    break;
                }
            }
            if(found){
                vis[curr] = i;
                break;
            }

        }

        for(auto& next: gph[curr]){
            if(next != parent){
                dfs(gph, vis, next, curr);
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> gph(n, vector<int>());
    for(int i = 0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        gph[u].push_back(v);
        gph[v].push_back(u);
    }
    vector<int> vis(n, -1);
    dfs(gph, vis, 0, -1);
    cout << 1+(*max_element(begin(vis), end(vis))) << endl;
    return 0;
}