// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    ll n, k, x;
    cin >> n >> k >> x;
    string s;
    cin >> s;
    x--;
    vector<ll> p;
    ll last = 0;
    ll acc = 0;
    for(int i = 0; i<n; i++){
        if(s[i] == '*'){
            acc += k;
        }
        else{
            if(acc>0)
                p.push_back(acc+1);
            p.push_back(-1);
            acc = 0;
        }
    }
    if(acc != 0){
        p.push_back(acc+1);
    }
    //for(auto& e: p){
    //    cerr << e << " ";
    //}
    //cerr << endl;
    string ans;
    int idx = p.size()-1;
    while(idx >= 0){
        if(p[idx] > 0){
            ll rem = x%p[idx];
            ans += string(rem, 'b');
            x /= p[idx];
        }
        else{
            ans.push_back('a');
        }
        idx--;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << nl;
    return 0;
}

int main(){
    FASTIO
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}