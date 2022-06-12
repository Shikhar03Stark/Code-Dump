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

int countNodes(vector<vector<int>> &gp, int node, int parent, vector<int> &nodes){
    int ans = 1;
    for(auto& next: gp[node]){
        if(next != parent){
            ans += countNodes(gp, next, node, nodes);
        }
    }
    return nodes[node] = ans;
}

int f(vector<vector<int>> &gp, int node, int parent, vector<int> &nodes){
    vector<int> child;
    for(auto& next: gp[node]){
        if(next != parent){
            child.push_back(next);
        }
    }
    if(child.size() == 0 ) return 0;
    if(child.size() == 1) return nodes[child[0]]-1;

    // if(nodes[child[0]] > nodes[child[1]]){
    //     return nodes[child[0]]-1 + f(gp, child[1], node, nodes);
    // }
    // else{
    //     return nodes[child[1]]-1 + f(gp, child[0], node, nodes);
    // }
    return max(nodes[child[0]]-1 + f(gp, child[1], node, nodes), nodes[child[1]]-1 + f(gp, child[0], node, nodes));
}

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> gp(n+1);
    for(int i = 0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        gp[u].push_back(v);
        gp[v].push_back(u);
    }
    vector<int> nodes(n+1, 0);
    countNodes(gp, 1, -1, nodes);
    cout << f(gp, 1, -1, nodes) << nl;


    return;
}

int main(){
    FASTIO
    pre();
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}