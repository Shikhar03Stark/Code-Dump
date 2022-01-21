// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int count(vector<vector<int>> &gp, int node, int k, int parent, vector<int> &cat){
    if(k<=0 || (cat[node] && k==1)){
        return 0;
    }
    bool isleaf = true;
    int ans = 0;
    for(auto& next: gp[node]){
        if(next != parent){
            isleaf = false;
            if(cat[node]){
                ans += count(gp, next, k-1, node, cat);
            }
            else{
                ans += count(gp, next, k, node, cat);
            }
        }
    }

    return (isleaf?1:ans);

}

int paths(vector<vector<int>> &gp, vector<int> &cat, int maxK, int node, int parent, int k, bool prevCat){
    if(k<0 || (k==0 && cat[node])){
        return 0;
    }
    bool isleaf = true;
    int ans = 0;

    for(auto& next: gp[node]){
        if(next != parent){
            isleaf = false;
            if(cat[node]){
                ans += paths(gp, cat, maxK, next, node, k-1, true);
            }
            else{
                ans += paths(gp, cat, maxK, next, node, maxK, false);
            }
        }
    }

    return (isleaf?1:ans);

}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> cat(n+1);
    for(int i = 1; i<=n; i++){
        cin >> cat[i];
    }
    vector<vector<int>> gp(n+1);
    for(int i = 0; i<n-1; i++){
        int u,v;
        cin >> u >> v;
        gp[u].push_back(v);
        gp[v].push_back(u);
    }

    int ans = paths(gp, cat, k, 1, -1, k, false);
    cout << ans << nl;
    return;
}

int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}