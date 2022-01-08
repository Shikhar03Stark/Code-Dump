// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    for(int k = 0; k<q; k++){
        int l,r;
        cin >> l >> r;
        l--, r--;
        int first = s.find(s[l]);
        int last = s.find_last_of(s[r]);

        if(first != l || last != r){
            cout << "YES" << nl;
        }
        else{
            cout << "NO" << nl;
        }
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