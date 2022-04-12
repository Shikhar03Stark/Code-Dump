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
    bool eq = true;
    bool hasone = false;
    for(int i = 0; i<n;i++){
        if(arr[i] == 1) hasone = true;
        if(i<n-1 && arr[i] != arr[i+1]){
            eq = false;
            // break;
        }
    }
    if(eq){
        cout << "YES" << nl;
    }
    else{
        if(!hasone)
            cout << "YES" << nl;
        else{
            sort(arr.begin(), arr.end());
            for(int i = 0; i<n-1; i++){
                if(arr[i+1]-arr[i] == 1){
                    cout << "NO" << nl;
                    return;
                }
            }
            cout << "YES" << nl;
        }
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