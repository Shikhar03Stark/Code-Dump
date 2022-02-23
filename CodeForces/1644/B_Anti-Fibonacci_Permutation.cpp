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

void pa(vector<int> &arr){
    for(auto& e: arr){
        cout << e << " ";
    }
    cout << nl;
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n,1);
    for(int i = n-2; i>=0; i--){
        arr[i] = arr[i+1] + 1;
    }
    pa(arr);
    for(int i = 0; i<n-1; i++){
        swap(arr[i], arr[i+1]);
        pa(arr);
        swap(arr[i], arr[i+1]);
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