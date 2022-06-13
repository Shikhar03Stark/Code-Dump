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
    vector<int> a(n), b(n);
    for(auto& e: a){
        cin >> e;
    }
    for(auto& e: b){
        cin >> e;
    }
    int mops = 1e4;
    int ops = 0;
    vector<pair<int,int>> ans;
    for(int i = 1; i<n; i++){
        for(int j = 0; j<i; j++){
            if(a[j] > a[i]){
                swap(a[i], a[j]);
                swap(b[i],b[j]);
                ans.push_back({j+1, i+1});
                ops++;
            }
        }
    }
    if(is_sorted(b.begin(), b.end())){
        cout << ans.size() << nl;
        for(auto& e: ans){
            cout << e.first << " " << e.second << nl;
        }
    }
    else{
        for(int i = 1; i<n; i++){
            for(int j = 0; j<i; j++){
                if(b[j] > b[i]){
                    swap(a[i], a[j]);
                    swap(b[i],b[j]);
                    ans.push_back({j+1, i+1});
                    ops++;
                }
            }
        }

        if(is_sorted(a.begin(), a.end()) && ops <= mops){
            cout << ans.size() << nl;
            for(auto& e: ans){
                cout << e.first << " " << e.second << nl;
            }
        }
        else{
            cout << -1 << nl;
        }
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