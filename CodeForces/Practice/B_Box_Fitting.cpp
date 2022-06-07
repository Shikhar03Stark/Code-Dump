// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

ll max2;

void pre(){
    ll x = 1;
    while(x<=1e6){
        x *= 2LL;
    }
    max2 = x;
    return;
}

int boxes(map<ll,int> &cnt, int bit, int w, int prev){
    if(bit<0) return 0;
    if((w&(1<<bit)) == 0){
        return boxes(cnt, bit-1, w, 0);
    }
    else{
        if(cnt[1<<bit] > 0){
            cnt[1<<bit]--;
            return 1 + boxes(cnt, bit-1, w, 1);
        }
        else{
            int c = 0;
            for(int i = bit-1; i>=0; i--){
                if(cnt[1<<i] > 0){
                    cnt[1<<i]--;
                    c++;
                }
            }
            return c;
        }
    }
}

void solve(){
    ll n, w;
    cin >> n >> w;
    multiset<int> arr;
    for(int i = 0; i<n; i++){
        int data;
        cin >> data;
        arr.insert(data);
    }
    int used = 0;
    int height = 1;
    int left = w;
    while(!arr.empty()){
        auto it = arr.upper_bound(left);
        if(it != arr.begin()){
            it--;
            int val = *it;
            left -= val;
            arr.erase(it);
            // used++;
        }
        else{
            left = w;
            height++;
        }
    }
    cout << height << nl;
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