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
    int n = s.size();
    if(n%2 == 0){
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += s[i]-'a' + 1;
        }
        cout << "Alice" << " " << sum << nl;
    }
    else{
        if(n==1){
            cout << "Bob" << " " << s[0]-'a'+1 << nl;
        }
        else{
            int sum = 0;
            for(int i = 0; i<n; i++){
                sum += s[i] - 'a' + 1;
            }
            cout << "Alice" << " " << max(sum - 2*(s[0] - 'a' + 1), sum - 2*(s[n-1] - 'a' + 1)) << nl;;
        }
    }
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