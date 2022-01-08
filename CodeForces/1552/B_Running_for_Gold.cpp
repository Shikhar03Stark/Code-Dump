#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

void dfs(vector<vector<int>>& graph, int curr, set<int>& s){
    if(s.find(curr) != end(s)){
        return;
    }
    s.insert(curr);
    for(auto& adj: graph[curr]){
        dfs(graph, adj, s);
    }
}

bool better(vector<vector<int>> &ranks, int i, int j){
    int cnt = 0;
    for(int k = 0; k<5; k++){
        if(ranks[i][k] < ranks[j][k]) cnt++;
    }
    if(cnt >= 3) return true;
    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> rank(n, vector<int>(5, 0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<5; j++){
                cin >> rank[i][j];
            }
        }

       int ans = 0;
       for(int i = 1; i<n; i++){
           if(better(rank, i, ans)) ans = i;
       }

        bool ok = true;
        for(int i = 0; i<n; i++){
            if(i!=ans){
                if(better(rank, i, ans)){
                    ok = false;
                }
            }
        }
        if(ok){
            cout << ans+1 << endl;
        }
        else{
            cout << -1 << endl;
        }

    }
    return 0;
}