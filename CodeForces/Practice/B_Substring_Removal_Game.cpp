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
    vector<int> len;
    string s;
    cin >> s;
    int i = 0;
    int n = s.size();
    while(i<n){
        if(s[i]=='0'){
            i++;
            continue;
        }
        int j = i;
        while(j<n && s[j] == '1') j++;
        len.push_back(j-i);
        i = j;
    }
    sort(len.rbegin(), len.rend());
    int ans = 0;
    for(int i = 0; i<len.size(); i+=2){
        ans += len[i];
    }
    cout << ans << nl;
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