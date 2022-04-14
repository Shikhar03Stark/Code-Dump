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

string pat = "abacaba";


int checkOne(string &s){
    int n = s.size();
    int cnt = 0;
    for(int i = 0; i+6<n; i++){
        if(s.substr(i, 7) == "abacaba"){
            cnt++;
        }
    }
    return cnt;
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n<7){
        cout << "NO" << nl;
    }
    else{
        for(int i = 0; i+6<n; i++){
            string t = s;
            bool match = true;
            for(int j = 0; j<7; j++){
                if(s[i+j] == '?' || s[i+j] == pat[j]){
                    t[i+j] = pat[j];
                }
                else{
                    match = false;
                    break;
                }
            }
            if(match){
                if(checkOne(t) == 1){
                    for(int i = 0; i<n; i++){
                        if(t[i] == '?'){
                            t[i] = 'z';
                        }
                    }
                    cout << "YES" << nl;
                    cout << t << nl;
                    return;
                }
            }
        }
        cout << "NO" << nl;

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