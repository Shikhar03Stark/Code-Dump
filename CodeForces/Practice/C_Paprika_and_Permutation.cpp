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
    vector<int> arr;
    set<int> S;
    for(int i = 1; i<=n; i++) S.insert(i);
    for(int i = 0; i<n; i++){
        int e;
        cin >> e;
        if(S.find(e) != S.end()) S.erase(e);
        else arr.push_back(e);
    }
    sort(arr.begin(), arr.end());
    int cnt = 0;
    bool pos = true;
    for(auto& e: arr){
        auto itr = S.begin();
        int val = *itr;
        if(val<=ceil(e/2.0)-1){
            cnt++;
            S.erase(itr);
        }
        else{
            pos = false;
            break;
        }
    }

    cout << (pos?cnt:-1) << endl;
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