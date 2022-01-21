// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> rep(10, 0);
    for(auto& e: s){
        int c = e-'0';
        if(c == 2 || c==3 || c==5 || c==7){
            rep[c]++;
        }
        else if(c==4){
            rep[3]++;
            rep[2] += 2;
        }
        else if(c==6){
            rep[5]++;
            rep[3]++;
        }
        else if(c==8){
            rep[7]++;
            rep[2] += 3;
        }
        else if(c==9){
            rep[7]++;
            rep[3] += 2;
            rep[2]++;
        }
    }
    for(auto& e: rep){
        cerr << e << " ";
    }
    for(int i = 9; i>1; i--){
        for(int j = 0; j<rep[i]; j++){
            cout << i;
        }
    }
    cout << nl;
    return;
}

int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}