// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

bool ispos(unordered_map<char,int> h, int x, int n, int k){
    if(x>n) return false;
    int ans = x;
    int left = n-x;
    int among = k-1;
    while(among>0){
        int val = left/among;
        for(char c = 'a'; c<='z'; c++){
            if(h[c]==1){
                val++;
                h[c]--;
                break;
            }
        }
        ans = min(ans, val);
        left -= left/among;
        among--;
    }

    if(ans == x) return true;
    return false;
}

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    unordered_map<char, int> h;
    for(auto& e: s){
        h[e]++;
    }
    int cpairs = 0, codds = 0;
    for(char c = 'a'; c<='z'; c++){
        cpairs += h[c]/2;
        codds += h[c]%2;
    }
    int ans = 2*(cpairs/k);
    int left = 2*(cpairs%k);
    codds += left;
    if(codds>=k){
        ans++;
    }
    cout << ans << nl;

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