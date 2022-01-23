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
    vector<string> arr(n);
    for(auto& s: arr){
        cin >> s;
    }
    map<string,bool> h;
    for(auto s: arr){
        string t = s;
        bool ispalin = true;
        for(int i = 0; i<s.size(); i++){
            if(s[i]!=s[s.size()-i-1]){
                ispalin = false;
            }
        }
        if(ispalin){
            cout << "YES" << nl;
            return;
        }
        reverse(t.begin(), t.end());
        if(h[t] == true){
            cout << "YES" << nl;
            return;
        }
        t = t.substr(0, t.size()-1);
        if(h[t] == true){
            cout << "YES" << nl;
            return;
        }
        if(s.size()==3){
            if(s[0] == s[1]){
                string t(1, s[2]);
                if(h[t]==true){
                    cout << "YES" << nl;
                    return;
                }
            }
        }
        h[s] = true;
        // t = s.substr(0, s.size()-1);
        // h[t] = true;
        //cerr << s << nl << t << nl;
    }
    h.clear();
    for(auto s: vector<string>(arr.rbegin(), arr.rend())){
        string t = s;
        reverse(t.begin(), t.end());
        if(h[t]==true){
            cout << "YES" << nl;
            return;
        }
        if(h[t.substr(1)]==true){
            cout << "YES" << nl;
            return;
        }
        if(s.size()==3){
            if(s[1]==s[2]){
                string t(1, s[0]);
                if(h[t]==true){
                    cout << "YES" << nl;
                    return;
                }
            }
        }
        h[s] = true;
    }
    //cerr << nl;
    cout << "NO" << nl;
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