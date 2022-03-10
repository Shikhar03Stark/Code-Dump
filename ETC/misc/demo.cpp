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

ll wbfs(map<int, vector<pair<int,int>>> &gp, int start, int dest){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, start});
    map<int, int> dist;
    for(auto& e: gp){
        dist[e.first] = 1e8;
    }
    dist[start] = 0;
    while(!pq.empty()){
        auto p = pq.top(); pq.pop();
        for(auto& e: gp[p.second]){
            int next = e.first;
            int w = e.second;
            if(dist[next] > dist[p.second] + w){
                dist[next] = dist[p.second] + w;
                pq.push({dist[next], next});
            }
        }
    }

    return dist[dest]==1e8?-1:dist[dest];
}

void solve(){
    int n;
    vector<int> vtx(n);
    for(int i = 0; i<n; i++){
        cin >> vtx[i];
    }
    int edges;
    cin >> edges;
    map<int, vector<pair<int,int>>> gp;
    for(int i = 0; i<edges; i++){
        int u, v, w;
        gp[u].push_back({v,w});
    }
    int start, end;
    cin >> start >> end;
    cout << wbfs(gp, start, end) << endl;
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