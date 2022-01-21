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
    if(arr[0] == 1){
        cout << n+1 << " ";
        for(int i = 1; i<=n; i++){
            cout << i << " ";
        }
        cout << nl;
        return;
    }
    if(arr[n-1] == 0){
        for(int i = 1; i<=n; i++){
            cout << i << " ";
        }
        cout << n+1 << nl;
        return;
    }
    int bridge = -1;
    for(int i = 0; i<n-1; i++){
        if(arr[i] == 0 && arr[i+1]==1){
            bridge = i+1;
            break;
        }
    }
    if(bridge>=0){
        for(int i = 1; i<=n; i++){
            if(i==bridge){
                cout << i << " " << n+1 << " ";
            }
            else{
                cout << i << " ";
            }
        }
        cout << nl;
        return;
    }
    else{
        cout << -1 << nl;
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