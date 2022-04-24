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
    ll sum = 0;
    int n = s.size();
    for(int i = 0; i<n; i++){
        sum += s[i]-'0';
    }
    if(sum%9 == 0){
        int i = 1;
        while(i<n && 0>=s[i]-'0'){
            i++;
        }
        s.insert(s.begin()+i, '0');
        cout << s << nl;
    }
    else{
        int rem = 9-(sum%9);
        int i = 0;
        while(i<n && rem>=s[i]-'0'){
            i++;
        }
        s.insert(s.begin()+i, rem+'0');
        cout << s << nl;
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