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
    vector<bool> m(n,false);
    for(int i = 1; i<n-1; i++){
        if(arr[i-1] < arr[i] && arr[i] > arr[i+1]){
            m[i] = true;
        }
    }
    int cnt = 0;
    for(int i = 1; i<n-1; i++){
        if(m[i-1] && m[i+1]){
            arr[i] = max(arr[i-1], arr[i+1]);
            cnt++;
            m[i-1] = m[i+1] = false;
        }
    }
    for(int i = 1; i<n-1; i++){
        if(m[i]){
            arr[i] = max(arr[i-1], arr[i+1]);
            m[i] = false;
            cnt++;
        }
    }
    cout << cnt << nl;
    for(auto& e: arr){
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