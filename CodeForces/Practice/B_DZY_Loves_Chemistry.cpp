// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void pre(){
    
    return;
}

void dfs(vector<vector<int>> &gp, int node, int cc, vector<int> &vis){
    vis[node] = cc;
    for(auto& next: gp[node]){
        if(vis[next] == 0){
            dfs(gp, next, cc, vis);
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> gp(n);
    for(int i = 0; i<m; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        gp[u].push_back(v);
        gp[v].push_back(u);
    }
    vector<int> vis(n);
    int cc = 0;
    for(int i = 0; i<n; i++){
        if(vis[i]==0){
            dfs(gp, i, cc+1, vis);
            cc++;
        }
    }
    cout << (ll)pow(2, n-cc) << nl;
    return;
}

int main(){
    FASTIO
    pre();
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}