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

bool possible(vector<char> &seq, map<char,int> &cnt, int k, int nt){
    ll sum = 0;
    for(int i = 1; i<=k; i++){
        sum += i*cnt[seq[i-1]];
    }
    if(sum == nt){
        return true;
    }
    return false;
}

bool verify(string s, string t, vector<char> &seq){
    string tt = "";
    while(t.size()>0){
        tt += s;
        //erase all seq[i]
    }
    return false;
}

void solve(){
    string t;
    cin >> t;
    int n = t.size();
    map<char, int> h;
    vector<char> seq;
    for(int i = n-1; i>=0; i--){
        if(h.count(t[i])==0){
            seq.push_back(t[i]);
        }
        h[t[i]]++;
    }
    reverse(seq.begin(), seq.end());
    int k = seq.size();
    map<char,int> mp;
    for(int i = 0; i<n; i++){
        mp[t[i]]++;
        if(possible(seq, mp, k, n) && verify(t.substr(0,i+1), t, seq)){
            cout << t.substr(0, i+1) << " ";
            for(auto& e: seq){
                cout << e;
            }
            cout << nl;
            return;
        }
    }
    cout << -1 << nl;
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