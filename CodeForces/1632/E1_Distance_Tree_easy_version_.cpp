// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void bfs(vector<vector<pair<int,int>>> &gp, int root, vector<int> &dist){
    int n = gp.size()-1;
    vector<bool> vis(n+1, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, root});
    while(!pq.empty()){
        auto[cost, node] = pq.top(); pq.pop();
        vis[node] = true;
        dist[node] = min(dist[node], cost);
        for(auto& next: gp[node]){
            if(!vis[next.first]){
                pq.push({cost+next.second, next.first});
            }
        }
    }
    return;
}

void solve(){
    int n;
    cin >> n;
    vector<vector<pair<int,int>>> gp(n+1);
    for(int i = 0; i<n-1; i++){
        int u,v;
        cin >> u >> v;
        gp[u].push_back({v, 1});
        gp[v].push_back({u, 1});
    }
    vector<int> lone;
    queue<int> Q;
    Q.push(1);
    vector<bool> vis(n+1,false);
    while(!Q.empty()){
        int sz = Q.size();
        if(sz==1){
            if(Q.front()!=1){
                lone.push_back(Q.front());
            }
        }
        for(int i = 0; i<sz; i++){
            int node = Q.front(); Q.pop();
            vis[node] = true;
            for(auto& next: gp[node]){
                if(!vis[next.first]){
                    Q.push(next.first);
                }
            }
        }
    }

    lone.push_back(1);

    for(int x = 1; x<=n; x++){
        int ans = 2*n+1;
        for(auto& e: lone){
            gp[1].push_back({e, x});
            gp[e].push_back({1, x});
            vector<int> dist(n+1,INT_MAX);
            bfs(gp, 1, dist);
            ans = min(ans, *max_element(dist.begin()+1, dist.end()));
            gp[1].pop_back();
            gp[e].pop_back();
        }
        cout << ans << " ";
    }
    cout << nl;

    return;
}

int main(){
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}