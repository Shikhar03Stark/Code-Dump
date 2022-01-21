// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> deg(n+1);
    vector<vector<int>> gp(n+1);
    for(int i = 0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        gp[u].push_back(v);
        gp[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    queue<int> Q;
    for(int i = 1; i<=n; i++){
        if(deg[i]<=1){
            Q.push(i);
        }
    }
    int rem = 0;
    while(!Q.empty() && k>0){
        int size = Q.size();
        rem += size;
        for(int i = 0; i<size; i++){
            int node = Q.front(); Q.pop();
            deg[node]--;
            for(auto& next: gp[node]){
                deg[next]--;
                if(deg[next] == 1){
                    Q.push(next);
                }
            }
        }
        k--;
    }
    // int left = 0;
    // for(int i = 1; i<=n; i++){
    //     if(deg[i]>0){
    //         left++;
    //     }
    // }
    cout << n-rem << nl;
    //cout << left << nl;
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