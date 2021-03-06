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
    int n;
    cin >> n;
    vector<int> arr(n);
    int maxi = 0;
    for(auto& e: arr){
        cin >> e;
        maxi = max(maxi, e);
    }
    vector<int> mod(3, 0);
    int optimal = 0;
    for(int i = 0; i<n; i++){
        mod[(maxi-arr[i])%3]++;
        int x = (maxi-arr[i]);
        optimal += (x%3==0)?(2*x):(2*x+1);
    }
    if(mod[0] >= 2){
        //optimal days
        cout << optimal <<nl;
        return;
    }
    if(mod[1] == 0 && mod[2] == 0){
        cout << optimal << nl;
        return;
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