// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void fn(string &s, int idx, vector<int> &flip, bool small){
    if(idx < 0){
        return;
    }
    else{
        char c = (small)?*min_element(s.begin(), s.begin()+idx):*max_element(s.begin(), s.begin()+idx);
        for(int i = idx; i>=0; i--){
            if(s[i] == c){
                flip[i] = 1;
                fn(s, i-1, flip, !small);
                break;
            }
            else{
                flip[i] = 0;
            }
        }
    }
}

int solve(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> flip(n, 0);
    bool small = true;
    fn(s, n-1, flip, small);
    for(auto& e: flip){
        cout << e << " ";
    }
    cout << nl;
    return 0;
}

int main(){
    FASTIO
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}