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
    vector<int> ones(30, 0);
    for(int i = 0; i<30; i++){
        for(int j = 0; j<n; j++){
            ones[i] += (arr[j]&(1<<i))>0?1:0;
        }
    }
    // for(auto& e: ones){
    //     cerr << e << " ";
    // }
    // cerr << nl;
    for(int a = 1; a<=n; a++){
        bool divall = true;
        for(int i = 0; i<30; i++){
            if(ones[i]%a != 0){
                divall = false;
                break;
            }
        }
        if(divall){
            cout << a << " ";
        }
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