// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    int n, h;
    cin >> n >> h;
    vector<int> b(n);
    for(auto& e: b){
        cin >> e;
    }

    vector<int> arr;
    int ans = 0;
    for(int i = 0; i<n; i++){
        arr.push_back(b[i]);
        for(int j = i; j>0; j--){
            if(arr[j]<arr[j-1]){
                swap(arr[j], arr[j-1]);
            }
        }
        int sh = 0;
        for(int j = i; j>=0; j-=2){
            if(j-1>=0){
                sh += max(arr[j], arr[j-1]);
            }
            else{
                sh += arr[j];
            }
        }

        if(sh>h){
            break;
        }
        ans = i+1;
    }
    // for(auto& e: arr){
    //     cerr << e << " ";
    // }
    // cerr << nl;
    cout << ans << nl;
    return;
}

int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}