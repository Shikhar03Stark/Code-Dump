// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

vector<int> factors(int n){
    vector<int> ans;
    for(int i = 1; i*i<=n; i++){
        if(n%i==0){
            if(i==n/i){
                ans.push_back(i);
            }
            else{
                ans.push_back(i);
                ans.push_back(n/i);
            }
        }
    }
    return ans;
}

bool islucky(int n){
    while(n>0){
        int d = n%10;
        if(d!=4 && d!=7){
            return false;
        }
        n /= 10;
    }
    return true;
}

void solve(){
    int n;
    cin >> n;
    vector<int> f = factors(n);
    for(auto& e: f){
        if(islucky(e)){
            cout << "YES" << nl;
            return;
        }
    }
    cout << "NO" << nl;

    return;
}

int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}