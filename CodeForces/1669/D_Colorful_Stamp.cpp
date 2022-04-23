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

bool check(string &s){
    int n = s.size();
    if(n==1){
        if(s[0] != 'W') return false;
        return true;
    }
    // bool lw = true;
    if(n == 2){
        if(s[0] == s[1] && s[0] != 'W'){
            return false;
        }
        // return true;
    }
    int i = 0;
    while(i<n){
        if(s[i] == 'W'){
            i++;
            continue;
        }
        int j = i;
        bool diff = false;
        while(j<n && s[j] != 'W'){
            if(j>i && s[j-1] != s[j]) diff = true;
            j++;
        }
        j--;
        if (!diff) return false;
        if(j-i+1 == 1) return false;
        i = j+1;
    }

    return true;

}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool ans = check(s);
    reverse(s.begin(), s.end());
    ans &= check(s);
    cout << (ans?"YES":"NO") << nl;
    return;
    // bool pos = true;
    // if(n == 1 && s[0] != 'W'){
    //     pos = false;
    //     cout << "NO" << nl;
    //     return;
    // }
    // if(n == 2){
    //     if(s[0] == s[1] && s[0] != 'W'){
    //         pos = false;
    //         cout << "NO" << nl;
    //         return;
    //     }
    // }
    // if(s[0] != s[1] && s[1] == 'W'){
    //     pos = false;
    //     cout << "NO" << nl;
    //     return;
    // }
    // if(s[n-1] != s[n-2] && s[n-2] == 'W'){
    //     pos = false;
    //     cout << "NO" << nl;
    //     return;
    // }
    

    // for(int i = 1; i<n-1; i++){
    //     if(s[i] != 'W'){
    //         if(s[i-1] == s[i+1] && s[i+1] == 'W'){
    //             pos = false;
    //             cout << "NO" << nl;
    //             return;
    //         }
    //         if(s[i] == s[i-1] && s[i] == s[i+1]){
    //             pos = false;
    //             cout << "NO" << nl;
    //             return;
    //         }
    //     }
    // }
    // cout << "YES" << nl;
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