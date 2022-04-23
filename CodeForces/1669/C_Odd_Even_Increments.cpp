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
    bool sameP = true;
    for(int i = 2; i<n; i+=2){
        if(arr[i]%2 != arr[i-2]%2){
            sameP = false;
            break;
        }
    }
    for(int i = 3; i<n; i+=2){
        if(arr[i]%2 != arr[i-2]%2){
            sameP = false;
            break;
        }
    }
    if(sameP){
        cout << "YES" << nl;
    }
    else{
        cout << "NO" << nl;
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