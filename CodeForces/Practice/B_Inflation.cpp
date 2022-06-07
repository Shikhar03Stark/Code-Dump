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
    ll n, k;
    cin >> n >> k;
    vector<double> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    double sum = 0;
    sum = arr[0];
    ll inc = 0;
    for(int i = 1; i<n; i++){
        double v = (100*arr[i] - k*sum)/k;
        if(v > 0){
            inc += ceil(v);
            sum += ceil(v);
        }
        sum += arr[i];
    }
    cout << inc << nl;
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