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
    bool pos = true;
    int delta = 0;
    for(int i = 0; i<n-1; i++){
        if(arr[i]-arr[i+1]>1){
            // cout << "NO" << endl;
            pos = false;
            break;
        }
    }
    if(arr[n-1] < arr[n-2]){
        pos = false;
    }
    cout << (pos?"YES":"NO") << endl;
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