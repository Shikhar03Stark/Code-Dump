// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> p1(n);
    int p1min = INT_MAX, p1max = INT_MIN;
    for(auto& e: p1){
        cin >> e.first >> e.second;
        p1min = min(p1min, e.second);
        p1max = max(p1max, e.first);
    }
    int m;
    cin >> m;
    vector<pair<int,int>> p2(m);
    int p2min = INT_MAX, p2max = INT_MIN;
    for(auto& e: p2){
        cin >> e.first >> e.second;
        p2min = min(p2min, e.second);
        p2max = max(p2max, e.first);
    }
    int ans = 0;
    ans = max(p2max-p1min, ans);
    ans = max(p1max-p2min, ans);
    cout << ans << endl;
    return 0;
}

int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}