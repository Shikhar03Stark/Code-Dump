// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    int n, l;
    cin >> n >> l;
    vector<int> bits(l+1);
    for(int i = 0; i<n; i++){
        int num;
        cin >> num;
        for(int j = 0; j<=l; j++){
            bits[j] += (num&(1<<j))>0?1:0;
        }
    }
    int num = 0;
    for(int i = 0; i<=l; i++){
        if(bits[i]>n/2){
            num += pow(2,i);
        }
    }
    cout << num << nl;
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