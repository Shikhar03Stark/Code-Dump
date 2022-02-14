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

bool isplain(const string& s, int st, int ed){
    int n = s.size();
    for(int i = 0; i<=(ed-st)/2; i++){
        if(s[st+i] != s[ed-i]){
            return false;
        }
    }
    return true;
}

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    string ans;
    int i,j;
    for(i = 0, j = n-1; i<j; i++, j--){
        if(s[i] == s[j]){
            ans.push_back(s[i]);
        }
        else{
            //i--, j++;
            break;
        }
    }
    string t = "", p = ans;
    int leftk = i-1;
    for(int k = i; k<=j; k++){
        if(isplain(s, i, k)){
            leftk = k;
        }
    }
    int rightk = j+1;
    for(int k = j; k>=i; k--){
        if(isplain(s, k, j)){
            rightk = k;
        }
    }
    if(leftk-i > j-rightk && leftk-i>=0){
        t = s.substr(i, leftk-i+1);
    }
    else if(j-rightk >= 0){
        t = s.substr(rightk, j-rightk+1);
    }
    ans = ans + t;
    reverse(p.begin(), p.end());
    ans = ans + p;

    cout << ans << nl;
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