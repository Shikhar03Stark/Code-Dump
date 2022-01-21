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
    int len = 1;
    int last = -1;
    for(int i = 0; i<n; i++){
        if(arr[i]==0 && i-last >= 2){
            cout << -1 << nl;
            return;
        }
        else if(i>0 && arr[i]==1 && arr[i-1]==1){
            len += 5;
            last = i;
        }
        else if(arr[i]==1){
            len++;
            last = i;
        }
    }
    cout << len << nl;
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