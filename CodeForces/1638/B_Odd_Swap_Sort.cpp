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
    set<int> ev, od;
    for(int i = 0; i<n; i++){
        if(arr[i]%2==0){
            if(ev.upper_bound(arr[i]) != ev.end()){
                cout << "No" << nl;
                return;
            }
            ev.insert(arr[i]);
        }
        else{
            if(od.upper_bound(arr[i]) != od.end()){
                cout << "No" << nl;
                return;
            }
            od.insert(arr[i]);
        }
        
    }
    cout << "Yes" << nl;

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