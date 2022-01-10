// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    int n;
    cin >> n ;
    string s;
    cin >> s;
    int cnt = 0;
    for(int i = n-1; i>=0; i--){
        if(i==n-1){
            int d = s[i]-'0';
            cnt += d;
        }
        else{
            int d = s[i]-'0';
            if(d>0){
                cnt += d+1;
            }
        }
    }

    cout << cnt << nl;
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