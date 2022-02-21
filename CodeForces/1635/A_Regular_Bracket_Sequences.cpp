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

void genSeq(vector<string> &ans, string s, int open, int close, int &cnt){
    if(cnt>0 && open>=0 && close>=0 && open<=close){
        if(open==0 && close==0){
            ans.push_back(s);
            cnt--;
            return;
        }
        if(open==close){
            s.push_back('(');
            genSeq(ans, s, open-1, close, cnt);
            s.pop_back();
        }
        else if(open<close){
            s.push_back(')');
            genSeq(ans, s, open, close-1, cnt);
            s.pop_back();
            s.push_back('(');
            genSeq(ans, s, open-1, close, cnt);
        }
    }
}

void solve(){
    int n;
    cin >> n;
    vector<string> ans;
    int cnt = n;
    genSeq(ans, "", n, n, cnt);
    for(auto& e: ans){
        cout << e << nl;
    }
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