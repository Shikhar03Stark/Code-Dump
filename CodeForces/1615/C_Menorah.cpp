// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    int n;
    cin >> n;
    string a, b;
    cin >> a;
    cin >> b;
    vector<int> one(2, 0);
    for(int i = 0; i<n; i++){
        one[0] += a[i]-'0';
        one[1] += b[i]-'0';
    }
    if(abs(one[1]-one[0]) > 1 || one[0]==0){
        cout << -1 << endl;
        return 0;
    }
    vector<int> parity(2,0);
    for(int i = 0; i<n; i++){
        if(a[i]!=b[i]){
            parity[1]++;
        }
        else{
            parity[0]++;
        }
    }
    cout << min(parity[0], parity[1]) << nl;
    return 0;
}

int main(){
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}