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
    vector<pair<int, int>> opp;
    opp.push_back({0, 8});
    opp.push_back({1, 7});
    opp.push_back({2, 6});
    opp.push_back({3, 5});
    opp.push_back({4, 4});
    opp.push_back({5, 3});
    opp.push_back({6, 2});
    opp.push_back({7, 1});
    opp.push_back({8, 0});

    vector<string> grid(3);
    for(auto& e: grid){
        cin >> e;
    }
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            int x = 3*i + j;
            if(grid[i][j] == 'X'){
                int y = opp[x].second;
                int r = y/3, c = y%3;
                if(grid[r][c] != 'X'){
                    cout << "NO" << nl;
                    return;
                }
            }
        }
    }
    cout << "YES" << nl;

    return;
}

int main(){
    FASTIO
    pre();
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}