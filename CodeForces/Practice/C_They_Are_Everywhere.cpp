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
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n==1){
        cout << 1 << nl;
        return;
    }
    vector<int> uniq(n);
    set<char> S;
    int ma = 0;
    for(int i = 0; i<n; i++){
        S.insert(s[i]);
        uniq[i] = S.size();
        ma = max(ma, uniq[i]);
    }
    if(ma == 1){
        cout << 1 << nl;
        return;
    }
    int ans = n+1;
    for(int i = 0; i<n; i++){
        auto bit = uniq.begin();
        int one = upper_bound(bit, bit+i, 1) - bit;
        int last = lower_bound(bit+i, uniq.end(), ma) - bit;
        ans = min(ans, last-one+2);
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