#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

bool dfs(vector<vector<pair<int,int>>> &gp, int node, int role, vector<int> &team, vector<int> &cnt){
    team[node] = role;
    cnt[role]++;
    for(auto& next: gp[node]){
        if(team[next.first] != -1){
            if(team[node]^next.second != team[next.first]){
                return false;
            }
        }
        else{
            if(dfs(gp, next.first, team[node]^next.second, team, cnt) == false) return false;
        }
    }

    return true;
}

int solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> gp(n);
    for(int i = 0; i<m; i++){
        int u, v;
        string type;
        cin >> u >> v >> type;
        u--;
        v--;
        if(type=="imposter"){
            gp[u].push_back({v,1});
            gp[v].push_back({u,1});
        }
        else{
            gp[u].push_back({v,0});
            gp[v].push_back({u,0});
        }
    }
    vector<int> cnt(2,0);
    vector<int> team(n,-1);
    int ans = 0;
    bool pos = true;
    for(int i = 0; i<n; i++){
        if(team[i]==-1){
            cnt[0] = cnt[1] = 0;
            if(dfs(gp, i, 0, team, cnt) == false){
                pos = false;
                break;
            }
            ans += max(cnt[0], cnt[1]);
        }
    }

    cout << (pos?ans:-1) << endl;

    return 0;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}