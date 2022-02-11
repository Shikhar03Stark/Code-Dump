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

struct TrieNode{
    bool leaf;
    char c; 
    TrieNode** next;

    TrieNode(){
        next = new TrieNode*[26];
        for(int i = 0; i<26; i++){
            next[i] = nullptr;
        }
    }

    void addString(const string& s, int i = 0){
        int n = s.size();
        if(i<n){
            if(next[s[i]-'a'] == nullptr){
                TrieNode* nt = new TrieNode();
                nt->c = s[i];
                if(i==n-1){
                    nt->leaf = true;
                }
                else{
                    next[s[i]-'a'] = nt;
                    nt->addString(s, i+1);
                }
            }
            else{
                if(i==n-1){
                    next[s[i]-'a']->leaf = true;
                }
                else{
                    next[s[i]-'a']->addString(s, i+1);
                }
            }
        }
    }
    
};

void solve(){
    string s, g;
    cin >> s;
    cin >> g;
    int k;
    cin >> k;
    
    return;
}

int main(){
    FASTIO
    pre();
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}