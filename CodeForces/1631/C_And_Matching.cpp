// 4 0
// 4 1
// 4 2
// 4 3
// 8 0
// 8 1
// 8 2
// 8 3
// 8 4
// 8 5
// 8 6
// 8 7
// 16 0
// 16 1
// 16 2
// 16 3
// 16 4
// 16 5
// 16 6
// 16 7
// 16 8
// 16 9
// 16 10
// 16 11
// 16 12
// 16 13
// 16 14
// 16 15
// 32 0
// 32 1
// 32 2
// 32 3
// 32 4
// 32 5
// 32 6
// 32 7
// 32 8
// 32 9
// 32 10
// 32 11
// 32 12
// 32 13
// 32 14
// 32 15
// 32 16
// 32 17
// 32 18
// 32 19
// 32 20
// 32 21
// 32 22
// 32 23
// 32 24
// 32 25
// 32 26
// 32 27
// 32 28
// 32 29
// 32 30
// 32 31
// 64 0
// 64 1
// 64 2
// 64 3
// 64 4
// 64 5
// 64 6
// 64 7
// 64 8
// 64 9
// 64 10
// 64 11
// 64 12
// 64 13
// 64 14
// 64 15
// 64 16
// 64 17
// 64 18
// 64 19
// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    ll n, k;
    cin >> n >> k;
    if(k==0){
        for(int i = 0; i<n/2; i++){
            cout << i << " " << n-i-1 << nl;
        }
    }
    else if(k==3 && n==4){
        cout << -1 << nl;
    }
    else if(k<n-1){
        cout << k << " " << n-1 << nl;
        cout << 0 << " " << n-k-1 << nl;
        for(int i = 1; i<n/2; i++){
            if(i!=k && i!=n-k-1){
                cout << i << " " << n-i-1 << nl;
            }
        }
    }
    else{
        cout << 0 << " " << 1 << nl;
        cout << (n-1)/2 << " " << k << nl;
        cout << n/2 << " " << n-2 << nl;
        for(int i = 2; i<n/2; i++){
            if(i!=(n-1)/2 && i!=n/2){
                cout << i << " " << n-i-1 << nl;
            }
        }
    }
    return;
}

int main(){
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}