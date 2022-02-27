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
    string s;
    cin >> s;
    vector<int> a(3), b(3);
    int delta = 0;
    for(int i = 0; i<3; i++){
        a[i] = s[i]-'0';
        b[i] = s[i+3]-'0';
        delta += b[i] - a[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if(delta < 0){
        swap(a, b);
        delta = -delta;
    }
    if(delta == 0){
        cout << 0 << nl;
        return;
    }
    if(delta <= 9-a[0] || delta <= b[2]){
        cout << 1 << nl;
    }
    else if(delta <= 9-a[0] + 9-a[1] || delta <= b[2] + b[1] || delta <= 9-a[0] + b[2]){
        cout << 2 << nl;
    }
    else{
        cout << 3 << nl;
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