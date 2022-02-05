// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    //unordered_map<char,int> h;
    int ans = 0;
    vector<bool> h(n,false);
    for(int i = 0; i+2<n; i++){
        string t = s.substr(i,3);
        if(t=="abc"){
            // h[i] = 1;
            h[i] = true;
            ans++;
        }
    }
    for(int x = 0; x<q; x++){
        int p;
        char c;
        cin >> p >> c;
        p--;
        if(s[p] == c){
            cout << ans << nl;
            continue;
        }

        string t1 = "",t2 = "",t3 = "";
        if(p<n-1){
            string t = s.substr(p,3);
            t1 += c;
            t1 += s.substr(p+1,2);
            if(t1 == "abc"){
                ans++;
            }
            else if(t == "abc"){
                ans--;
            }
        }
        if(p<n-1 && p>0){
            string t = s.substr(p-1, 3);
            t2 += s[p-1];
            t2 += c;
            t2 += s[p+1];
            if(t2 == "abc"){
                ans++;
            }
            else if(t == "abc"){
                ans--;
            }
        }
        if(p>1){
            string t = s.substr(p-2, 3);
            t3 += s[p-2];
            t3 += s[p-1];
            t3 += c;
            if(t3 == "abc"){
                ans++;
            }
            else if(t == "abc"){
                ans--;
            }
        }
        s[p] = c;
        cout << max(0,ans) << nl;
    }
    return;
}

int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}