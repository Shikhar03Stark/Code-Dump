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

void solve(){
    int n, m;
    cin >> n >> m;
    map<int, pair<int,vector<pair<int,int>>>> edges;
    for(int i = 0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges[w].first++;
        edges[w].second.push_back({u,v});
        edges[w].second.push_back({v,u});
    }

    vector<tuple<int,int,vector<pair<int,int>>>> arr;
    for(auto& p: edges){
        arr.push_back({p.second.first, p.first, p.second.second});
    }
    sort(arr.rbegin(), arr.rend());

    vector<int> dsu(n+1, -1);
    int ans = 0;
    for(auto& e: arr){
        for(auto& ed: get<2>(e)){
            int u = ed.first, v = ed.second;
            int p1 = find(dsu, u), p2 = find(dsu, v);
            if(p1!=p2){
                if(p1>p2){
                    swap(p1,p2);
                }
                dsu[p1] += dsu[p2];
                dsu[p2] = p1;
                ans = (ans|get<1>(e));
            }
        }
    }
    cout << ans << nl;

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