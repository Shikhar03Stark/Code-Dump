// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

const int N = 3e5 + 10;

int memo[N];

void pre(){
    int x = 0;
    for(int i = 0; i<N; i++){
        if(i){
            memo[i] = (memo[i-1]^i);
        }
        else{
            memo[i] = 0;
        }
    }
}

void solve(){
    int a, b;
    cin >> a >> b;
    int x = memo[a-1];
    if(x == b){
        cout << a << nl;
    }
    else{
        int y = b^x;
        if(y == a){
            cout << a + 2 << nl;
        }
        else{
            cout << a + 1 << nl;
        }
    }
    return;
}

int main(){
    pre();
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}