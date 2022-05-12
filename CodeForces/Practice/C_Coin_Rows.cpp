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
    vector<vector<int>> point(2, vector<int>(n));
    vector<vector<int>> prefix(2, vector<int>(n+1));
    for(auto& row: point){
        for(auto& e: row){
            cin >> e;
        }
    }

    for(int i = 0; i<n; i++){
        prefix[0][i+1] = prefix[0][i] + point[0][i];
        prefix[1][i+1] = prefix[1][i] + point[1][i];
    }

    int tot = prefix[0][n] + prefix[1][n];

    int ans = tot;
    int res = 0;
    for(int i = 0; i<n; i++){
        ans = min(ans, max(prefix[1][i], prefix[0][n] - prefix[0][i+1]));
    }

    cout << ans << nl;
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