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
    sort(arr.begin(), arr.end());
    bool haszero = (arr[0]==0);
    if(haszero){
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(arr[i]>0) cnt++;
        }
        cout << cnt << nl;
        return;
    }
    
    bool haseq = false;
    for(int i = 0; i<n-1; i++){
        if(arr[i] == arr[i+1]){
            haseq =  true;
            break;
        }
    }

    if(haseq){
        cout << n << nl;
    }
    else{
        cout << n+1 << nl;
    }

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