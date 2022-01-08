#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

bool dfs(vector<vector<int>> &gp, int node, int level, vector<int> &vis, int parent){
    if(vis[node] <= level ){
        return false;
    }
    if(node != 1 && gp[node].size() == 1){
        return true;
    }
    for(auto &adj: gp[node]){
        if(adj != parent && level+1<vis[adj]){
            if(dfs(gp, adj, level+1, vis, node)) return true;
        }
    }
    return false;
}

int solve(){
    int n, k;
    cin >> n >> k;
    //vector<int> ene(k);
    queue<int> q;
    vector<int> edist(n+1, -1);
    for(int i = 0; i<k; i++){
        int ene;
        cin >> ene;
        q.push(ene);
        edist[ene] = 0;
    }
    vector<vector<int>> gp(n+1);
    for(int i = 0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        gp[u].push_back(v);
        gp[v].push_back(u);
    }

    //int level = 0;
    while(!q.empty()){
        int node = q.front(); q.pop();
        edist[node] = (edist[node]==-1)?0:edist[node];
        for(auto next: gp[node]){
            if(edist[next] == -1){
                edist[next] = 1+edist[node];
                q.push(next);
            }
        }
    }

    for(auto d: edist){
        cerr << d << " ";
    }
    cerr << endl;
    int ans = dfs(gp, 1, 0, edist, 0);
    cout << (ans?"YES":"NO") << endl;
    return 0;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}