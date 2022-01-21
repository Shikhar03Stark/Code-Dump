// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

bool isprime(int n){
    if(n==2 || n==3){
        return true;
    }
    for(int i = 2; i*i<=n; i++){
        if(n%i==0) return false;
    }
    return true;
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool one = false;
    for(int i = 0; i<n; i++){
        int c = s[i] - '0';
        if(c == 1 || c==4 || c==6 || c==8 || c==9){
            one = true;
            cout << 1 << nl;
            cout << c << nl;
            return;
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(i!=j){
                string t;
                t.push_back(s[i]);
                t.push_back(s[j]);
                int num = stoi(t);
                if(!isprime(num)){
                    cout << 2 << nl;
                    cout << num << nl;
                    return;
                }
            }
        }
    }
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