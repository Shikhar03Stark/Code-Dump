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
    vector<int> cnt(n+1, 0);
    for(int i = 0; i<n; i++){
        bool filled = false;
        while(arr[i]){
            if(!filled && arr[i]<=n && cnt[arr[i]]==0){
                cnt[arr[i]]++;
                filled = true;
            }
            arr[i] /= 2;
        }
    }
    bool pos = true;
    for(int i = 1; i<=n; i++){
        if(cnt[i] == 0){
            pos = false;
            break;
        }
    }
    cout << (pos?"YES":"NO") << nl;
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