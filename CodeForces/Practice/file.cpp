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
    int n, m;
    cin >> n >> m;
    vector<int> arr(n+m+1);
    for(int i = 1; i<=n+m; i++){
        cin >> arr[i];
    }
    map<int,int> idx;
    for(int i = 1; i<m+n+1; i++){
        idx[arr[i]] = i;
    }
    vector<int> half(n+m+1, 0);
    for(int i = n+1; i<n+m+1; i++){
        cerr << i << " ";
        half[arr[i]] = 1;
    }
    cerr << nl;
    for(int i = 1; i<n+m+1; i++){
        cerr << half[arr[i]] << ":" << arr[i] << " ";
    }
    cerr << nl;
    int ans = 0;
    for(int i = n+m; i>0; i--){
        if(i != arr[i]){
            if((half[arr[i]]^half[i]) == 1){
                ans++;
                int i2 = idx[i];
                swap(half[arr[i]], half[i]);
                swap(arr[idx[i]], arr[idx[i]]);
                idx[arr[i]] = i2;
                idx[i] = i;
            }
            else{
                ans += 3;
                int i2 = idx[i];
                swap(arr[idx[i]], arr[idx[i]]);
                idx[arr[i]] = i2;
                idx[i] = i;
            }
        }
    }
    cout << ans << endl;
    return;
}

int main(){
    FASTIO
    pre();
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}