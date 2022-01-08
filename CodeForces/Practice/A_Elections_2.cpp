// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    ll a, b ,c;
    cin >> a >> b >> c;
    ll mx = max(b,c);
    if(a > mx){
        cout << 0 << " ";
    }
    else{
        cout << mx-a+1 << " ";
    }
    mx = max(a,c);
    if(b > mx){
        cout << 0 << " ";
    }
    else{
        cout << mx-b+1 << " ";
    }
    mx = max(a,b);
    if(c > mx){
        cout << 0 << " ";
    }
    else{
        cout << mx-c+1 << " ";
    }
    cout << endl;
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