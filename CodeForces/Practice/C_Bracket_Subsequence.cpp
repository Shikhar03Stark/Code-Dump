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
    stack<int> S;
    vector<int> open(n);
    for(int i = 0; i<n; i++){
        if(s[i] == '('){
            S.push(i);
            open[i] = -1;
        }
        else{
            open[i] = S.top(); S.pop();
        }
    }
    vector<int> pos;
    for(int i = 0; i<n; i++){
        if(open[i] >= 0){
            if(k>0){
                pos.push_back(open[i]);
                pos.push_back(i);
                k -= 2;
            }
        }
    }
    sort(pos.begin(), pos.end());
    string ans;
    for(int i = 0; i<pos.size(); i++){
        ans.push_back(s[pos[i]]);
    }
    cout << ans << nl;
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