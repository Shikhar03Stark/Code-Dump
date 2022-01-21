// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    auto comp = [&](pair<int,int> &a, pair<int,int> &b){
        int d1 = abs(n/2 - a.first) + abs(m/2 - a.second);
        int d2 = abs(n/2 - b.first) + abs(m/2 - b.second);
        return d1<d2;
    };

    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq(comp);

    pq.push({n/2, m/2});
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vis[n/2][m/2] = true;
    vector<int> ans;
    while(!pq.empty()){
        auto [r, c] = pq.top(); pq.pop();
        int dist = 0;
        dist = max(dist, r+c);
        dist = max(dist, (int)abs(n-1-r)+c);
        dist = max(dist, (int)abs(m-1-c)+r);
        dist = max(dist, (int)abs(n-1-r)+abs(m-1-c));
        //vis[r][c] = true;
        ans.push_back(dist);
        int nr, nc;
        nr = r+1; nc = c;
        if(nr >=0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]){
            vis[nr][nc] = true;
            pq.push({nr,nc});
        }
        nr = r; nc = c+1;
        if(nr >=0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]){
            vis[nr][nc] = true;
            pq.push({nr,nc});
        }
        nr = r; nc = c-1;
        if(nr >=0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]){
            vis[nr][nc] = true;
            pq.push({nr,nc});
        }
        nr = r-1; nc = c;
        if(nr >=0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]){
            vis[nr][nc] = true;
            pq.push({nr,nc});
        }

        nr = r+1; nc = c+1;
        if(nr >=0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]){
            vis[nr][nc] = true;
            pq.push({nr,nc});
        }
        nr = r+1; nc = c-1;
        if(nr >=0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]){
            vis[nr][nc] = true;
            pq.push({nr,nc});
        }
        nr = r-1; nc = c+1;
        if(nr >=0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]){
            vis[nr][nc] = true;
            pq.push({nr,nc});
        }
        nr = r-1; nc = c-1;
        if(nr >=0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]){
            vis[nr][nc] = true;
            pq.push({nr,nc});
        }
    }
    sort(ans.begin(), ans.end());
    //cerr << ans.size() << nl;
    for(int i = 0; i<m*n; i++){
        cout << ans[i] << " ";
    }
    cout << nl;
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