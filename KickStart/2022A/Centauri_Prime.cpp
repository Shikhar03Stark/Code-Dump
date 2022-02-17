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

vector<char> vow = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

void solve(){
    string s;
    cin >> s;
    if(s[s.size()-1] == 'y' || s[s.size()-1] == 'Y'){
        cout << s << " is ruled by nobody." << nl;
        return;
    }
    for(auto& e: vow){
        if(e==s[s.size()-1]){
            cout << s << " is ruled by Alice." << nl;
            return;
        }
    }
    cout << s << " is ruled by Bob." << nl;
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