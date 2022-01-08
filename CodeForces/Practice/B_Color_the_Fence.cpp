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
    vector<int> cost(11);
    vector<pair<int,int>> order(10, {1e9,0});
    for(int i = 1; i<10; i++){
        cin >> cost[i];
        order[i] = {cost[i], i};
    }
    sort(order.begin(), order.end());
    if(order[0].first > n){
        cout << -1 << endl;
        return 0;
    }
    vector<int> ans;
    while(n-order[0].first>=0){
        ans.push_back(order[0].second);
        n -= order[0].first;
    }

    for(int i = ans.size()-1; i>=0; i--){
        n += cost[ans[i]];
        for(int j = 9; j>0; j--){
            if(cost[j] <= n){
                ans[i] = j;
                break;
            }
        }

        n -= cost[ans[i]];
    }

    reverse(ans.begin(), ans.end());
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i];
    }

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