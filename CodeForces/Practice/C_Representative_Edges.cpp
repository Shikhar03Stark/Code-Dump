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
    if(n == 2){
        cout << 0 << nl;
        return;
    }
    int changes = INT_MAX;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            int cnt = 0;
            for(int k = 0; k<n; k++){
                if((j-i)*(arr[k]-arr[i]) != (k-i)*(arr[j]-arr[i])){
                    cnt++;
                }
            }
            changes = min(changes, cnt);
        }
    }

    cout << min(changes, n-1) << nl;
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