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
    map<int,int> cnt;
    for(int i = 0; i<n; i++){
        cnt[arr[i]]++;
    }
    int k = 1;
    for(int i = 0; i<n; i++){
        k = max(k, cnt[arr[i]]);
    }
    int ops = 0;
    while(true){
        if(k>=n){
            break;
        }
        if(2*k<n){
            ops += k+1;
            k *= 2;
        }
        else{
            ops += n-k+1;
            k += n-k+1;
        }
    }
    cout << ops << nl;
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