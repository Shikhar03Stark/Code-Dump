// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int dfs(vector<vector<int>> &gp, int node, int parent, vector<int> &deg, set<int> &unread){
    if(node > parent){
        if(unread.find(node) != unread.end() && deg[node] == 0){
            unread.erase(node);
            int read = 1;
            for(auto& next: gp[node]){
                deg[next]--;
                read += dfs(gp, next, node, deg, unread);
            }

            return read;
        }
        return 0;
    }
    return 0;
}

void solve(){
    int n;
    cin >> n;
    set<int> unread;
    vector<vector<int>> gp(n+1);
    vector<int> deg(n+1,0);
    for(int i = 1; i<=n; i++){
        unread.insert(i);
        int reqs;
        cin >> reqs;
        for(int j = 0; j<reqs; j++){
            int parent;
            cin >> parent;
            gp[parent].push_back(i);
            deg[i]++;
        }
    }
    int tot = 0;
    int times = 0;
    set<int> Q;
    int last = -1;
    for(int i = 1; i<=n; i++){
        if(deg[i]==0){
            Q.insert(i);
        }
    }
    vector<bool> done(n+1, false);
    //int times = 0;
    while(!Q.empty()){
        int ch;
        if(last==-1){
            ch = *Q.begin();
            Q.erase(ch);
        }
        else{
            auto ub = Q.upper_bound(last);
            if(ub == Q.end()){
                times++;
                last = -1;
                continue;
            }
            ch = *ub;
            Q.erase(ch);
        }
        done[ch] = true;
        for(int next: gp[ch]){
            deg[next]--;
            if(deg[next]==0 && !done[next]){
                Q.insert(next);
            }
        }
        last = ch;
    }
    bool pos = true;
    for(int i = 1; i<=n; i++){
        pos &= done[i];
    }
    if(pos){
        cout << times+1 << nl;
    }
    else{
        cout << -1 << nl;
    }
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