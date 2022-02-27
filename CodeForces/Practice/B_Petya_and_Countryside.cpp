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
    vector<int> R(n), L(n);
    for(int i = 0; i<n; i++){
        int r = 0, l = 0;
        for(int j = i+1; j<n && arr[j]<=arr[j-1]; j++){
            r++;
        }
        for(int j = i-1; j>=0 && arr[j]<=arr[j+1]; j--){
            l++;
        }
        R[i] = r;
        L[i] = l;
    }
    int ans = 0;
    for(int i = 0; i<n; i++){
        ans = max(L[i]+R[i]+1, ans);
    }
    cout << ans << nl;
    return;
}

int main(){
    FASTIO
    pre();
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}