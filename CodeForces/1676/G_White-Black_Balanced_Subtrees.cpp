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

int dfs(vector<vector<int>> &gp, string &s, int node, vector<int> &balance){
    int sum = 0;
    for(auto& next: gp[node]){
        sum += dfs(gp, s, next, balance);
    }
    if(s[node-1] == 'B'){
        sum--;
    }
    else{
        sum++;
    }
    return balance[node] = sum;
}

void solve(){
    int n;
    cin >> n;
    vector<int> p(n+1, -1);
    vector<vector<int>> gp(n+1);
    for(int i = 2; i<=n; i++){
        cin >> p[i];
        gp[p[i]].push_back(i);
    }

    string s;
    cin >> s;
    vector<int> balance(n+1,-1);
    dfs(gp, s, 1, balance);

    int cnt = 0;
    for(int i = 1; i<=n; i++){
        if(balance[i]==0) cnt++;
    }
    cout << cnt << nl;

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