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
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(auto& e: grid){
        cin >> e;
    }
    vector<vector<int>> steps;
    for(int i = n-1; i>=0; i--){
        for(int j = m-1; j>=0; j--){
            if(grid[i][j] == '1'){
                if(j>0){
                    steps.push_back({i+1, j, i+1, j+1});
                }
                else if(i>0){
                    steps.push_back({i, j+1, i+1, j+1});
                }
                else{
                    cout << -1 << nl;
                    return;
                }
            }
        }
    }
    cout << steps.size() << nl;
    for(auto& c: steps){
        for(auto& e: c){
            cout << e << " ";
        }
        cout << nl;
    }
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