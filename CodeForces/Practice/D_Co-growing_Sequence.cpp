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
    vector<int> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    vector<int> ans(n, 0);
    for(int i = 1; i<n; i++){
        for(int k = 0; k<30; k++){
            if((arr[i-1]&(1<<k)) > 0 && (arr[i]&(1<<k)) == 0){
                ans[i] = (ans[i]^(1<<k));
                arr[i] = (arr[i]^(1<<k));
            }
        }
    }
    for(auto& e: ans){
        cout << e << " ";
    }
    cout << nl;
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