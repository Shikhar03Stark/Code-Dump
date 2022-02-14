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

ll depth(vector<vector<int>> &gp, int node, int parent){
    ll ans = 0;
    for(auto& next: gp[node]){
        if(next!=parent){
            ans = max(ans, 1LL+depth(gp, next, node));
        }
    }
    return ans;
}

int diameter(vector<vector<int>> &gp, int node, int parent){
    return 0;
}

pair<int,int> farthestNode(vector<vector<int>> &gp, int node){
    queue<pair<int,int>> Q;
    Q.push({0, node});
    vector<bool> vis(gp.size(), false);
    pair<int,int> ans = {0, node};
    while(!Q.empty()){
        int sz = Q.size();
        for(int i = 0; i<sz; i++){
            auto[dist, node] = Q.front(); Q.pop();
            if(ans.first < dist){
                ans = {dist, node};
            }
            vis[node] = true;
            for(auto& next: gp[node]){
                if(!vis[next]){
                    Q.push({dist+1, next});
                }
            }
        }
    }

    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> gp(n);
    for(int i = 0; i<n-1; i++){
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        gp[u].push_back(v);
        gp[v].push_back(u);
    }
    int root = 0;
    for(int i = 0; i<n; i++){
        if(gp[i].size()==1){
            root = i;
            break;
        }
    }
    auto[d1, u] = farthestNode(gp, 0);
    auto[d2, v] = farthestNode(gp, u);
    cout << 3*d2 << nl;
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