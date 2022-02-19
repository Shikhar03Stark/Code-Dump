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

pair<vector<int>, int> maxDepth(vector<vector<int>> &gp, int root){
    int n = gp.size();
    vector<bool> vis(n, false);
    queue<int> Q;
    Q.push(root);
    vector<int> ans;
    int d = 0;
    while(!Q.empty()){
        int sz = Q.size();
        ans.clear();
        for(int i = 0; i<sz; i++){
            int node = Q.front(); Q.pop();
            vis[node] = true;
            ans.push_back(node);
            for(auto& next: gp[node]){
                if(!vis[next]){
                    Q.push(next);
                }
            }
        }
        d++;
    }

    return {ans, d};

}

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> gp(n);
    for(int i = 0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        gp[u].push_back(v);
        gp[v].push_back(u);
    }
    auto[A, d1] = maxDepth(gp, 0);
    set<int> crit;
    for(int i = 0; i<A.size(); i++){
        crit.insert(A[i]);
    }
    int depth = 0;
    for(auto& u: A){
        auto[B, d2] = maxDepth(gp, u);
        for(int i = 0; i<B.size(); i++){
            crit.insert(B[i]);
        }
        depth = d2-1;
    }
    for(int i = 0; i<n; i++){
        if(crit.find(i) != crit.end()){
            cout << depth + 1 << nl;
        }
        else{
            cout << depth << nl;
        }
    }
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