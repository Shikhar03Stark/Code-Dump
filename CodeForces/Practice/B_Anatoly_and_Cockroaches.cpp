// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    //rbr..
    int ans = n;
    {
        int br = 0, rb = 0;
        char c = 'r';
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(s[i] == 'b' && c == 'r'){
                br++;
            }
            else if(s[i] == 'r' && c == 'b'){
                rb++;
            }
            c = (c=='r')?'b':'r';
        }

        ans = min(ans, max(rb,br));
    }
    //brb...
    {
        int br = 0, rb = 0;
        char c = 'b';
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(s[i] == 'b' && c == 'r'){
                br++;
            }
            else if(s[i] == 'r' && c == 'b'){
                rb++;
            }
            c = (c=='r')?'b':'r';
        }

        ans = min(ans, max(rb,br));
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