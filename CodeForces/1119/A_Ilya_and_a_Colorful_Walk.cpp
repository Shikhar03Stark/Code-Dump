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
    vector<int> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    int dist = 0;
    for(int i = 0; i<n-1; i++){
        if(arr[i] != arr[n-1]){
            dist = n-1-i;
            break;
        }
    }
    for(int i = n-1; i>0; i--){
        if(arr[0] != arr[i]){
            dist = max(dist, i);
            break;
        }
    }
    cout << dist << nl;
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