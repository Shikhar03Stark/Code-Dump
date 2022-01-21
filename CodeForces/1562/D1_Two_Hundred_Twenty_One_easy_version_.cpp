// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int delta(vector<int> &bit, int x, int d){
    int n = bit.size();
    for(int i = x; i<=n; i+=(i&-i)){
        bit[i] += d;
    }
}

int sum(vector<int> &bit, int x){
    int n = bit.size();
    int sum = 0;
    for(int i = x; i>0; i -= (i&-i)){
        sum += bit[i];
    }
    return sum;
}

void solve(){
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> bo(n/2+2, 0), be(n/2+2, 0);
    for(int )
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