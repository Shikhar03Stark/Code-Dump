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
    vector<int> done(n+1, -1);
    int left = n;
    bool fin = false;
    int idx = 1;
    while(left>0){
        cout << "? " << idx <<endl;
        int val;
        cin >> val;
        done[idx] = val;
        left--;
        if(done[val] == -1){
            idx = val;
        }
        else{
            while(left>0 && done[idx]!=-1)
                (idx==n)?idx=1:idx++;
        }
    }
    cout << "! ";
    for(int i = 1; i<=n; i++){
        cout << done[i] << " ";
    }
    cout << endl;
    
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
