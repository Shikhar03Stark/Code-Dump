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
    string s, p;
    cin >> s >> p;
    int i = 0, j = 0;
    while(i<s.size() && j<p.size()){
        if(s[i] == p[j]){
            i++;
            j++;
        }
        else{
            j++;
        }
    }
    if(i == s.size()){
        cout << p.size()-s.size() << nl;
    }
    else{
        cout << "IMPOSSIBLE" << nl;
    }
    return;
}

int main(){
    FASTIO
    pre();
    int T=1;
    cin>>T;
    for(int z = 1; z<=T; z++){
        cout << "Case #" << z << ": ";
        solve();
    }
    return 0;
}