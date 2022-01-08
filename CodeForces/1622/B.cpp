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
    vector<int> p(n);
    for(auto &e: p){
        cin >> e;
    }
    string s;
    cin >> s;
    vector<tuple<char, int, int>> arr(n);
    for(int i = 0; i<n; i++){
        arr[i] = {s[i], p[i], i};
    }

    sort(arr.begin(), arr.end());

    vector<int> ans(n);
    for(int i = 0; i<n; i++){
        ans[get<2>(arr[i])] = i+1;
    }

    for(auto& e: ans){
        cout << e << " ";
    }
    cout << nl;


    return 0;
}

int main(){
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}