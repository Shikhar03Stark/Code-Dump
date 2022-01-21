// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int find(vector<int> &dsu, int x){
    return dsu[x]<0?x:dsu[x]=find(dsu, dsu[x]);
}

bool dunion(vector<int> &dsu, int u, int v){
    int p1 = find(dsu, u), p2 = find(dsu, v);
    if(p1!=p2){
        if(p1>p2){
            swap(p1,p2);
        }
        dsu[p1] += dsu[p2];
        dsu[p2] = p1;
        return true;
    }
    return false;
}

bool sameParent(vector<int> &dsu, int u, int v){
    int p1 = find(dsu, u), p2 = find(dsu, v);
    if(p1==p2){
        return true;
    }
    return false;
}

void solve(){
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<int> dsu1(n+1, -1), dsu2(n+1, -1);
    vector<pair<int,int>> ans;
    for(int i = 0; i<m1; i++){
        int u, v;
        cin >> u >> v;
        dunion(dsu1, u, v);
    }
    for(int i = 0; i<m2; i++){
        int u, v;
        cin >> u >> v;
        dunion(dsu2, u, v);
    }
    for(int i = 1; i<=n; i++){
        for(int j = i+1; j<=n; j++){
            if(sameParent(dsu1, i, j)==false && sameParent(dsu2, i,j)==false){
                dunion(dsu1, i, j);
                dunion(dsu2, i, j);
                ans.push_back({i,j});
            }
        }
    }
    cout << ans.size() << nl;
    for(auto& p: ans){
        cout << p.first << " " << p.second << nl;
    }
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