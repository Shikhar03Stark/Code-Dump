// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void dfs(vector<vector<pair<int,int>>> &gp, int node, int parent, int prev = -1){
    if(prev == -1){
        for(int i = 0; i < gp[node].size(); i++){
            if(i){
                if(gp[node][i].second == -1){
                    gp[node][i].second = 5;
                    dfs(gp, gp[node][i].first, node, 5);
                }
            }
            else{
                if(gp[node][i].second == -1){
                    gp[node][i].second = 2;
                    dfs(gp, gp[node][i].first, node, 2);
                }
            }
        }
    }
    else{
        for(auto& next: gp[node]){
            if(next.second == -1 && next.first != parent){
                next.second = (prev==2?5:2);
                dfs(gp, next.first, node, next.second);
            }
        }
    }
}

void solve(){
    int n;
    cin >> n;
    vector<vector<pair<int,int>>> gp(n+1);
    vector<int> deg(n+1);
    vector<pair<int,int>> order;
    bool deggt = false;
    for(int i = 0; i<n-1; i++){
        int u,v;
        cin >> u >> v;
        gp[u].push_back({v,-1});
        gp[v].push_back({u,-1});
        deg[u]++;
        deg[v]++;
        order.push_back({u,v});
        if(deg[u]>=3 || deg[v]>=3){
            deggt = true;
        }
    }

    if(deggt){
        cout << -1 << nl;
        return;
    }

    dfs(gp, 1, -1, -1);

    // for(int i = 1; i<=n; i++){
    //     cerr << i << ": ";
    //     for(auto& next: gp[i]){
    //         cerr << next.first << "<" << next.second << ">" << " ";
    //     }
    //     cerr << nl;
    // }
    // cerr << nl;

    for(auto& e: order){
        int u = e.first, v = e.second;
        bool done = false;
        for(auto& next: gp[u]){
            if(next.first == v && next.second != -1){
                cout << next.second << " ";
                done = true;
                break;
            }
        }
        if(done) continue;
        for(auto& next: gp[v]){
            if(next.first == u && next.second != -1){
                cout << next.second << " ";
                break;
            }
        }
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