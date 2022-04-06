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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(auto& e: arr){
        cin >> e ;
    }
    if(n == 1){
        cout << arr[0] << nl;
    }
    for(int i = 0; i<n-1; i++){
        if(k>=arr[i]){
            k -= arr[i];
            arr[n-1] += arr[i];
            arr[i] = 0;
        }
        else{
            arr[i] -= k;
            arr[n-1] += k;
            k = 0;
        }
    }
    for(auto& e: arr){
        cout << e << " ";
    }
    cout << nl;
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