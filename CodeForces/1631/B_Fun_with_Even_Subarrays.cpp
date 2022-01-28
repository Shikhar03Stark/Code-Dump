// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

ll f(vector<int> &arr, int n){
    if(n==1){
        return 0;
    }
    ll ans = 0;
    if(n%2==1 && arr[0] != arr[n-1]){
        ans++;
    }
    int k = n/2;
    bool same = true;
    for(int i = k+1; i<2*k;i++){
        if(arr[i] != arr[i-1]){
            same = false;
            break;
        }
    }
    if(same && arr[0]==arr[k]){
        return ans+f(arr, n/2);
    }
    else{
        return ans+1+f(arr, n/2);
    }

}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    reverse(arr.begin(), arr.end());
    ll ans = 0;//f(arr, n);
    int idx = 1;
    while(idx<n){
        if(arr[idx]!=arr[0]){
            int k;
            for(k = 0; k<idx && k+idx<n; k++){
                arr[k+idx] = arr[k];
            }
            ans++;
            idx = k-1;
        }
        idx++;
    }
    cout << ans << nl;
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