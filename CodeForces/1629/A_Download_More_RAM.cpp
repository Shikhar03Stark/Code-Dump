// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    int n, r;
    cin >> n >> r;
    vector<pair<int,int>> arr(n);
    for(auto& e: arr){
        cin >> e.first;
    }
    for(auto& e: arr){
        cin >> e.second;
    }
    sort(arr.begin(), arr.end());
    int i = 0;
    while(i<n && arr[i].first <= r){
        r += arr[i].second;
        i++;
    }
    cout << r << nl;
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