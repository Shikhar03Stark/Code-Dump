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
    vector<int> A(n), B(n);
    for(auto& e: A){
        cin >> e;
    }
    for(auto& e: B){
        cin >> e;
    }
    ll sum = 0;
    for(int i = 1; i<n; i++){
        if(abs(A[i-1] - A[i]) + abs(B[i-1]-B[i]) > abs(A[i-1]-B[i]) + abs(B[i-1]-A[i])){
            sum += abs(A[i-1]-B[i]) + abs(B[i-1]-A[i]);
            swap(A[i], B[i]);
        }
        else{
            sum += abs(A[i-1] - A[i]) + abs(B[i-1]-B[i]);
        }
    }
    
    cout << sum << nl;
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