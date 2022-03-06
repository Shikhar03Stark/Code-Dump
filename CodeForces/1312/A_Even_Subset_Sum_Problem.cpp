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
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    int od1=-1, od2=-1;
    for(int i = 0; i<n; i++){
        if(arr[i]%2==0){
            cout << 1 << nl;
            cout << (i+1) << nl;
            return;
        }
        else{
            if(od1==-1){
                od1 = i+1;
            }
            else if(od2==-1){
                cout << 2 << nl;
                cout << od1 << " " << (i+1) << nl;
                return;
            }
        }
    }
    cout << -1 << nl;
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