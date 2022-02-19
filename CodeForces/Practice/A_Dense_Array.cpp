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
    // sort(arr.begin(), arr.end());
    int ans = 0;
    for(int i = 0; i<n-1; i++){
        int y = max(arr[i], arr[i+1]);
        int x = min(arr[i], arr[i+1]);
        if((0.0+y)/x > 2){
            int k = ceil(log2((0.0+y)/x));
            ans += k-1;
        }
    }
    cout << ans << nl;
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