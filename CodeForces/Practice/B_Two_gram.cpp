#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<string,int> h;
    for(int i = 0; i+1<n; i++){
        string sub = s.substr(i, 2);
        h[sub]++;
    }
    string ans;
    int cnt = 0;
    for(auto& p: h){
        if(p.second > cnt){
            cnt = p.second;
            ans = p.first;
        }
    }
    cout << ans << endl;
    return 0;
}

int main(){
    solve();
    return 0;
}