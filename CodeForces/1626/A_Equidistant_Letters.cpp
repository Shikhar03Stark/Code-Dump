// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> h(26);
    for(auto& e: s){
        h[e-'a']++;
    }
    for(int i = 0; i<26; i++){
        for(int j = 0; j<h[i]; j++){
            cout << (char)(i + 'a');
        }
    }
    cout << nl;
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