// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void lowercase(string &s){
    int n = s.size();
    for(int i = 0; i<n; i++){
        if(s[i]>='A' && s[i]<='Z'){
            s[i] = 'a' + s[i] - 'A';
        }
    }
}

char vow[] = {'a', 'e', 'i', 'o', 'u', 'y'};

bool isvowel(char c){
    int n = sizeof(vow)/sizeof(char);
    for(int i = 0; i<n; i++){
        if(c == vow[i]) return true;
    }
    return false;
}

int solve(){
    string s;
    cin >> s;
    lowercase(s);
    string ans;
    int n = s.size();
    for(int i = 0; i<n; i++){
        if(!isvowel(s[i])){
            ans.push_back('.');
            ans.push_back(s[i]);
        }
    }
    cout << ans << nl;
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