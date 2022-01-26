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
    cin >> n;
    vector<int> boy(n);
    for(auto& e: boy){
        cin >> e;
    }
    sort(boy.begin(), boy.end());
    cin >> m;
    vector<int> girl(m);
    unordered_map<int,int> h;
    for(auto& e: girl){
        cin >> e;
        h[e]++;
    }
    int ans = 0;
    for(int i = 0; i<n; i++){
        if(h[boy[i] - 1] > 0){
            h[boy[i] - 1]--;
            ans++;
        }
        else if(h[boy[i]] > 0){
            h[boy[i]]--;
            ans++;
        }
        else if(h[boy[i]+1] > 0){
            h[boy[i]+1]--;
            ans++;
        }
    }
    cout << ans << nl;
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