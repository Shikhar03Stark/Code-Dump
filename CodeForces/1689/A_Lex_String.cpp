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
    int n, m, k;
    cin >> n >> m >> k;
    string s, t;
    cin >> s >> t;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    int i = 0, j = 0;
    string x;
    int cs = 0, ct = 0;
    while(i<n && j<m){
        if(s[i] <= t[j] && cs < k){
            x.push_back(s[i]);
            i++;
            cs++;
            ct = 0;
        }
        else if(s[i] <= t[j] && cs == k){
            x.push_back(t[j]);
            j++;
            cs = 0;
            ct++;
        }
        else if(s[i] > t[j] && ct < k){
            x.push_back(t[j]);
            j++;
            ct++;
            cs = 0;
        }
        else if(s[i] > t[j] && ct == k){
            x.push_back(s[i]);
            i++;
            cs++;
            ct = 0;
        }
    }
    cout << x << nl;
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