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
    sort(arr.begin(), arr.end());
    unordered_map<int,int> h;
    for(int i = 0; i<n; i++){
        h[arr[i]]++;
    }
    vector<int> mex(n+1);
    int zeros = lower_bound(arr.begin(), arr.end(), 1) - arr.begin();
    mex[0] = zeros;
    int excess = 0;
    for(int i = 1; i<=n; i++){
        if(mex[i-1] == -1){
            mex[i] = -1;
        }
        else{
            int lb = lower_bound(arr.begin(), arr.end(), i) - arr.begin();
            if(lb >= i){
                mex[i] = h[i];
                h[i+1] += h[i] + lb-i;
            }
            else{
                mex[i] = -1;
            }
        }
        
    }
    for(auto& e: mex){
        cout << e << " ";
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