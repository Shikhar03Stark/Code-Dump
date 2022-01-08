// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

bool isgood(string &s, string &t, int n, int m, int width){
    int i,j;
    for(i = 0, j = 0; i<n && j<m;){
        if(s[i]==t[j]){
            i += width;
            j++;
        }
        else{
            i++;
        }
    }
    if(j==m) return true;
    return false;
}

int solve(){
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    vector<int> L(m), R(m);
    for(int i = 0, j = 0; i<n && j<m; ){
        if(s[i] == t[j]){
            L[j] = i;
            i++;
            j++;
        }
        else{
            i++;
        }
    }

    for(int i = n-1, j = m-1; i>=0 && j>=0; ){
        if(s[i] == t[j]){
            R[j] = i;
            i--;
            j--;
        }
        else{
            i--;
        }
    }

    int mx = 0;
    for(int i = 0; i<m-1; i++){
        mx = max(mx, R[i+1]-L[i]);
    }
    cout << mx << nl;

    return 0;
}

int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}