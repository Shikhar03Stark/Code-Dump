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

void solve(){
    string s, t;
    cin >> s >> t;
    vector<int> cnt(26, 0);
    for(int i = 0; i<s.size(); i++){
        cnt[s[i]-'a']++;
    }
    if(t=="abc"){
        if(cnt[0]==0 || cnt[1] == 0 || cnt[2]==0){
            sort(s.begin(), s.end());
            cout << s << nl;
            return;
        }
        for(int i = 0; i<cnt[0]; i++){
            cout << 'a';
        }
        for(int i = 0; i<cnt[2]; i++){
            cout << 'c';
        }
        for(int i = 0; i<cnt[1]; i++){
            cout << 'b';
        }
        for(int i = 3; i<26; i++){
            for(int j = 0; j<cnt[i]; j++){
                cout << char('a'+i);
            }
        }
        cout << nl;
    }
    else{
        sort(s.begin(), s.end());
        cout << s << nl;
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