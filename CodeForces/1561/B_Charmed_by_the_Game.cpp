// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    int a, b;
    cin >> a >> b;
    set<int> ans;
    for(int i = 0; i<=b; i++){
        for(int j = 0; j<=a; j++){
            int bh = b-i, ah = a-j;
            if(bh>=0 && ah>=0){
                ans.insert(i+j);
            }
        }
    }
    cout << ans.size() << nl;
    for(auto& e: ans){
        cout << e << " ";
    }
    cout << nl;
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