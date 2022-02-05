// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(auto& e: a){
        cin >> e;
    }
    for(auto & e: b){
        cin >> e;
    }
    int delta = 0;
    map<int,int> inc, dec;
    for(int i = 0; i<n; i++){
        delta += a[i] - b[i];
        if(a[i]-b[i]>0){
            dec[i] = a[i]-b[i];
        }
        else if(a[i]-b[i]<0){
            inc[i] = b[i]-a[i];
        }
    }
    if(delta != 0){
        cout << -1 << nl;
    }
    else{
        // int ops = 0;
        vector<pair<int,int>> ans;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                while(dec[i]>0 && inc[j]>0){
                    ans.push_back({i,j});
                    dec[i]--;
                    inc[j]--;
                }
            }
        }
        cout << ans.size() << nl;
        for(auto& e: ans){
            cout << e.first+1 << " " << e.second +1 << nl;
        }
    }
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