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
    vector<int> ans(n);
    for(int i = 0; i<n; i++){
        ans[i] = i;
    }
    for(int i = n-1; i>=0; i--){
        if(i>0 && (i&(i-1))==0){
            ans[0] = ans[i-1];
            ans[i-1] = 0;
            break;
        }
    }
    for(auto& e: ans){
        cout << e << " ";
    }
    cerr << nl;
    cout << nl;
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