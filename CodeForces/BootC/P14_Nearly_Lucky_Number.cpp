// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 0;
    for(int i = 0; i<n; i++){
        if(s[i] == '4' || s[i] == '7'){
            cnt++;
        }
    }
    if(cnt == 4 || cnt == 7){
        cout << "YES" << nl;
    }
    else{
        cout << "NO" << nl;
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