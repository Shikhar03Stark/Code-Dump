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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<char,int> h;
    for(auto& e: s){
        h[e]++;
    }
    vector<int> freq;
    for(auto& p: h){
        freq.push_back(p.second);
    }

    sort(freq.rbegin(), freq.rend());

    ll ans = 0;
    ll left = k;
    for(int i = 0; i<freq.size(); i++){
        if(freq[i]<=left){
            ans += (ll)freq[i]*freq[i];
            left = left - freq[i];
        }
        else{
            ans += left*left;
            left = 0;
            break;
        }
    }
    cout << ans << nl;

    // auto comp = [&h](const char &a, const char &b)->bool{
    //     return h[a]>=h[b];
    // };

    // sort(s.begin(), s.end(), comp);
    // s = s.substr(0, k);
    // h.clear();
    // for(int i = 0; i<k; i++){
    //     h[s[i]]++;
    // }
    // // int ans = 0;
    // for(int i = 0; i<k; i++){
    //     ans += h[s[i]];
    // }
    // cout << ans << nl;

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