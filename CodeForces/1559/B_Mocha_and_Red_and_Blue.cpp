// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 1; i<n; i++){
        if(s[i]=='?'){
            if(s[i-1]=='B'){
                s[i] = 'R';
            }
            else if(s[i-1]=='R'){
                s[i] = 'B';
            }
        }
    }
    for(int i = n-2; i>=0; i--){
        if(s[i]=='?'){
            if(s[i+1]=='B'){
                s[i] = 'R';
            }
            else if(s[i+1] == 'R'){
                s[i] = 'B';
            }
        }
    }
    if(s[0] == '?'){
        s[0] = 'B';
        for(int i = 1;i<n; i++ ){
            if(s[i]=='?'){
                if(s[i-1]=='B'){
                    s[i] = 'R';
                }
                else if(s[i-1]=='R'){
                    s[i] = 'B';
                }    
            }
        }
    }
    cout << s << nl;
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