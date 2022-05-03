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

void solve(){
    int n;
    cin >> n;
    vector<string> grid(n);
    for(auto& s: grid){
        cin >> s;
    }
    vector<pair<int,int>> pt;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(grid[i][j] == '*'){
                pt.push_back({i, j});
            }
        }
    }
    if(pt[0].first == pt[1].first){
        if(pt[0].first == 0){
            pt.push_back({pt[0].first+1, pt[0].second});
            pt.push_back({pt[1].first+1, pt[1].second});
        }
        else{
            pt.push_back({pt[0].first-1, pt[0].second});
            pt.push_back({pt[1].first-1, pt[1].second});
        }
    }
    else if(pt[0].second == pt[1].second){
        if(pt[0].second == 0){
            pt.push_back({pt[0].first, pt[0].second+1});
            pt.push_back({pt[1].first, pt[1].second+1});
        }
        else{
            pt.push_back({pt[0].first, pt[0].second-1});
            pt.push_back({pt[1].first, pt[1].second-1});
        }
    }
    else{
        pt.push_back({pt[0].first, pt[1].second});
        pt.push_back({pt[1].first, pt[0].second});
    }
    grid[pt[2].first][pt[2].second] = '*';
    grid[pt[3].first][pt[3].second] = '*';
    for(auto& s: grid){
        cout << s << nl;
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