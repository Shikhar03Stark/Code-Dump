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
    int x = 0;
    for(int i = 0; i<n; i++){
        x = (x^arr[i]);
    }
    if(x == 0){
        cout << "YES" << nl;
    }
    else{
        int cnt = 0;
        int k = 0;
        for(int i = 0; i<n; i++){
            k = (k^arr[i]);
            if(k == x){
                cnt++;
                k = 0;
            }
        }
        if(cnt%2 == 1 && cnt>2){
            cout << "YES" << nl;
        }
        else{
            cout << "NO" << nl;
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