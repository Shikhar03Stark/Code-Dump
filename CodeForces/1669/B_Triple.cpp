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
    map<int,int> h;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
        h[arr[i]]++;
    }
    for(int i = 0; i<n; i++){
        if(h[arr[i]] >= 3){
            cout << arr[i] << nl;
            return;
        }
    }
    cout << -1 << nl;
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