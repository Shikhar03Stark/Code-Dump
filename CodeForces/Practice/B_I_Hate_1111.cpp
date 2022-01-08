#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

vector<ll> els;

bool solve(int x, int mask){
    ll res = x;
    int idx = 8;
    while(res>0 && idx>=0){
        if((mask&(1<<idx))>0){
            res = res%els[idx];
        }
        idx--;
    }

    if(res==0)
        return true;
    return false;
}

int main(){
    int t;
    cin>>t;
    ll ans = 1;
    while(ans<=1e10){
        ans *= 10;
        ans++;
        els.push_back(ans);
        cerr << ans << " ";
    }
    cerr << endl;

    while(t--){
        ll x;
        cin >> x;
        int idx = 8;
        
        bool pos = false;
        for(int i = 1; i<(1<<8); i++){
            if(solve(x, i)){
                cerr << i << endl;
                pos = true;
                break;
            }
        }

        cout << (pos?"YES":"NO") << endl;

    }
    return 0;
}