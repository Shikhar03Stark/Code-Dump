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

void dfs(vector<vector<int>> &gp, int node, int d, vector<int> &depth){
    depth[node] = d;
    for(auto& next: gp[node]){
        dfs(gp, next, d+1, depth);
    }
}

void solve(){
    int n;
    cin >> n;
    vector<int> p(n+1);
    vector<vector<int>> gp(n+1);
    vector<int> depth(n+1, 0);
    int root = 1;
    for(int i = 1; i<=n; i++){
        cin >> p[i];
        if(p[i] != i)
            gp[p[i]].push_back(i);
        if(p[i] == i) root = i;
    }

    dfs(gp, root, 0, depth);

    vector<pair<int,int>> arr;
    for(int i = 1; i<=n; i++){
        arr.push_back({depth[i], i});
    }
    sort(arr.rbegin(), arr.rend());

    vector<vector<int>> ans;
    vector<int> vis(n+1, -1);
    for(int i = 0; i<n; i++){
        if(vis[arr[i].second]<0){
            vector<int> t;
            int node = arr[i].second;
            while(vis[node]<0){
                t.push_back(node);
                vis[node] = 1;
                if(node != p[node])
                    node = p[node];
            }
            reverse(t.begin(), t.end());
            ans.push_back(t);
        }
    }

    cout << ans.size() << nl;
    for(auto& a: ans){
        cout << a.size() << nl;
        for(auto& e: a){
            cout << e << " ";
        }
        cout << nl;
    }
    // cout << nl;

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