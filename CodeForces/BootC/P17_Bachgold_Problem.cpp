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
    vector<int> ans;
    if(n&1==1){
        n -= 3;
        ans.push_back(3);
        while(n>0){
            n -= 2;
            ans.push_back(2);
        }
    }
    else{
        while(n>0){
            n -=2;
            ans.push_back(2);
        }
    }
    cout << ans.size() << nl;
    for(auto& e: ans){
        cout << e << " ";
    }
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