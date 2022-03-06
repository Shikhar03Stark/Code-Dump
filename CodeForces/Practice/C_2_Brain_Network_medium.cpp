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

pair<int,int> maxDist(vector<vector<int>> &gp, int node){
    int ans = node, ansd = 0;
    queue<int> Q;
    Q.push(node);
    set<int> vis;
    int lvl = 0;
    while(!Q.empty()){
        ansd = ++lvl;
        int sz = Q.size();
        for(int i = 0; i<sz; i++){
            int t = Q.front(); Q.pop();
            ans = t;
            vis.insert(t);
            for(auto& next: gp[t]){
                if(vis.find(next) == vis.end()){
                    Q.push(next);
                }
            }
        }
    }
    return {ans, ansd};
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

    pair<int,int> p1 = maxDist(gp, 0);
    pair<int,int> p2 = maxDist(gp, p1.first);

    cout << p2.second-1 << nl;

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