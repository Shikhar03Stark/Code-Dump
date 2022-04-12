// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

vector<int> p2(35000, 0);

int factor2(int n){
    int ans = 0;
    while(n>0 && n%2==0){
        ans++;
        n /= 2;
    }
    return ans;
}

void pre(){
    int p2sz = p2.size();
    for(int i = 1; i<p2sz; i++){
        p2[i] = factor2(i);
    }
    return;
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    for(auto e: arr){
        int ans = 16;
        if(e==0){
            cout << 0 << " ";
            continue;
        }
        for(int i = 0; i<=15; i++){
            ans = min(ans, max(0, 15-p2[e+i]+i));
        }
        cout << ans << " ";
    }
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