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
    int neg = 0;
    for(auto& e: arr){
        cin >> e;
        if(e<0) neg++;
    }
    for(int i = 0; i<n; i++){
        if(neg){
            arr[i] = -abs(arr[i]);
            neg--;
        }
        else{
            arr[i] = abs(arr[i]);
        }
    }

    if(is_sorted(arr.begin(), arr.end())){
        cout << "YES" << nl;
    }
    else{
        cout << "NO" << nl;
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