// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    int n;
    cin >> n;
    vector<int> arr(n), srr;
    for(auto& e: arr){
        cin >> e;
    }
    if(n==1){
        cout << "yes" << endl;
        cout << 1 << " " << 1 << endl;
        return 0;
    }
    srr = arr;
    sort(srr.begin(), srr.end());
    int segs = 1;
    int l = -1, r = -1;
    for(int i = 0; i<n; i++){
        if(arr[i] != srr[i]){
            l = i;
            r = i;
            break;
        }
    }
    for(int i = l+1; l>=0 && i<n; i++){
        if(arr[i-1]>arr[i]){
            r = i;
        }
        else{
            break;
        }
    }
    reverse(arr.begin()+l, arr.begin()+r+1);
    for(int i = 0; i<n; i++){
        if(arr[i] != srr[i]){
            segs = 2;
            break;
        }
    }
    if(l == -1){
        cout << "yes" << nl;
        cout << 1 << " " << 1 << nl;
    }
    else if(segs == 1){
        cout << "yes" << nl;
        cout << l+1 << " " << r+1 << nl;
    }
    else{
        cout << "no" << nl;
    }
    return 0;
}

int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}