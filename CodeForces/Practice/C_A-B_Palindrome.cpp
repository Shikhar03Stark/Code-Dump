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
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    int n = s.size();
    if(n==1){
        if(s[0] == '?'){
            if(a>b){
                s[0] = '0';
            }
            else{
                s[0] = '1';
            }
        }
        else{
            if(s[0] == '1' && a == 1){
                cout << -1 << nl;
                return;
            }
            if(s[0] == '0' && b == 1){
                cout << -1 << nl;
                return;
            }
        }
        cout << s << nl;
        return;
    }
    int l = 0, r = n-1;
    while(l<r){
        if(s[l] == '?' && s[r] == '?'){
            if(a>b){
                if(a>=2){
                    s[l] = '0';
                    s[r] = '0';
                    a -= 2;
                }
                else{
                    cout << -1 << nl;
                    return;
                }
            }
            else{
                if(b>=2){
                    s[l] = '1';
                    s[r] = '1';
                    b -=2;
                }
                else{
                    cout << -1 << nl;
                    return;
                }

            }
        }
        else if(s[l] == '?'){
            if(s[r] == '0'){
                if(a>0){
                    s[l] = '0';
                    a -= 2;
                }
                else{
                    cout << -1 << nl;
                    return;
                }
            }
            else{
                if(b>0){
                    s[l] = '1';
                    b -= 2;
                }
                else{
                    cout << -1 << nl;
                    return;
                }
            }
        }
        else if(s[r] == '?'){
            if(s[l] == '0'){
                if(a>0){
                    s[r] = '0';
                    a -= 2;
                }
                else{
                    cout << -1 << nl;
                    return;
                }
            }
            else{
                if(b>0){
                    s[r] = '1';
                    b -= 2;
                }
                else{
                    cout << -1 << nl;
                    return;
                }
            }
        }
        else{
            if(s[l] != s[r]) {
                cout << -1 << nl;
                return;
            }
            else{
                if(s[l] == '1'){
                    b -= 2;
                }
                else{
                    a -= 2;
                }
            }
        }
        if(a<0 || b<0){
            cout << -1 << nl;
            return;
        }
        l++;
        r--;
    }
    if(n%2==1){
        if(s[n/2] == '?'){
            if(a>b){
                s[n/2] = '0';
            }
            else{
                s[n/2] = '1';
            }
        }
    }
    cout << s << nl;
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