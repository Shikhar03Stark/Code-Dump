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

ll wbfs(map<ll, vector<pair<ll,ll>>> &gp, int start, int dest){
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0, start});
    map<int, ll> dist;
    for(auto& e: gp){
        dist[e.first] = 1e14;
    }
    dist[start] = 0;
    while(!pq.empty()){
        ll v = pq.top().second;
        ll d_v = pq.top().first;
        pq.pop();
        for(auto& e: gp[v]){
            int next = e.first;
            int w = e.second;
            if(dist[next] > dist[v] + w){
                dist[next] = dist[v] + w;
                pq.push({dist[next], next});
            }
        }
    }

    return dist[dest]==1e14?-1:dist[dest];
}

void solve(){
    int n;
    cin >> n;
    vector<int> vtx(n);
    for(int i = 0; i<n; i++){
        cin >> vtx[i];
    }
    int edges;
    cin >> edges;
    map<ll, vector<pair<ll,ll>>> gp;
    for(int i = 0; i<edges; i++){
        ll u, v, w;
        cin >> u >> v >> w;
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