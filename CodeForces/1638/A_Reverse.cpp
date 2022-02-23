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
    int tofind = 1;
    for(int i = 0; i<n; i++){
        if(i+1 != arr[i]){
            int l = i;
            for(int j = i; j<n; j++){
                if(arr[j] == i+1){
                    reverse(arr.begin()+l, arr.begin()+j+1);
                    break;
                }
            }
            break;
        }
    }
    for(auto& e: arr){
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