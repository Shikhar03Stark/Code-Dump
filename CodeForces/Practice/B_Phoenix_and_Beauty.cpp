// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    set<int> S;
    for(int i = 0; i<n; i++){
        int data;
        cin >> data;
        S.insert(data);
    }
    if(S.size()>k){
        cout << -1 << nl;
        return;
    }
    vector<int> arr(S.begin(), S.end());
    while(arr.size()<k){
        arr.push_back(arr[0]);
    }
    int sz = arr.size();
    cout << n*sz << nl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<sz; j++){
            cout << arr[j] << " ";
        }
    }
    cout << nl;
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