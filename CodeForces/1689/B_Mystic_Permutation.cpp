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
    if(n == 1) {
        cout << -1 << nl;
        return;
    }
    vector<int> A(n);
    for(int i = 0; i<n; i++){
        A[i] = i+1;
    }
    for(int i = 0; i<n-1; i++){
        if(arr[i] == A[i]){
            swap(A[i], A[i+1]);
        }
    }
    if(arr[n-1] == A[n-1]){
        swap(A[n-1], A[n-2]);
    }
    for(auto& e: A){
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