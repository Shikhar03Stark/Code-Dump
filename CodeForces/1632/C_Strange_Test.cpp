// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    int a_, b_;
    cin >> a_ >> b_;
    int a = a_, b = b_;
    int diff = b-a;
    int bops = 0;
    while(true){
        if(a==b){
            break;
        }
        if((a&b)==a){
            bops++;
            break;
        }
        else{
            b++;
        }
        bops++;
    }
    a = a_; b = b_;
    int aops = 0;
    while(true){
        if(a==b){
            break;
        }
        if((a&b)==a){
            aops++;
            break;
        }
        else{
            a++;
        }
        aops++;
    }
    cout << min({aops,diff, bops}) << nl;
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