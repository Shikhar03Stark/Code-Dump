// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    int l1, l2, l3;
    cin >> l1 >> l2 >> l3;
    vector<int> arr = {l1,l2,l3};
    sort(arr.begin(), arr.end());
    cerr << arr[0] << " " << arr[1] << " " << arr[2] << nl;
    if(arr[2] == arr[0]+arr[1]){
        cout << "YES" << nl;
    }
    else if(l1==l2 && ((l3&1)==0)){
        cout << "YES" << nl;
    }
    else if(l2==l3 && ((l1&1)==0)){
        cout << "YES" << nl;
    }
    else if(l1==l3 && ((l2&1)==0)){
        cout << "YES" << nl;
    }
    else{
        cout << "NO" << nl;
    }
    return 0;
}

int main(){
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}