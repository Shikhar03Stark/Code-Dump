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

/* OUTPUT
regression
e 2
g 1
i 1
n 1
o 1
r 2
s 2
*/

//sentence -> get the word which has maximum repeated char
// aaabb zzzzzzzz zzxy

void solve(){
    string word;
    cin >> word;
    map<char, int> h;
    for(auto &c: word){
        h[c]++;
    }
    for(auto& p: h){
        cout << p.first << " " << p.second << endl;
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