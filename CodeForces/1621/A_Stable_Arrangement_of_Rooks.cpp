// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    int n,k;
    cin >> n >> k;
    if(k<=(n+1)/2){
        vector<vector<char>> chess(n, vector<char>(n, '.'));
        int i = 0, j = 0;
        for(;k>0;i+=2,j+=2){
            chess[i][j] = 'R';
            k--;
        }

        for(auto& row: chess){
            for(auto& e: row){
                cout << e;
            }
            cout << nl;
        }
    }
    else{
        cout << -1 << nl;
    }
    return 0;
}

int main(){
    FASTIO
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}