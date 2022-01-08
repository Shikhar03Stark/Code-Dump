// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    int n, q;
    cin >> n >> q;
    set<int> row, col, up, down;
    while(q--){
        int i, j;
        cin >> i >> j;
        if(row.find(i) != row.end()){
            cout << "NO" << nl;
        }
        else if(col.find(j) != col.end()){
            cout << "NO" << nl;
        }
        else if(up.find(j+i) != up.end()){
            cout << "NO" << nl;
        }
        else if(down.find(j-i) != down.end()){
            cout << "NO" << nl;
        }
        else{
            //can be put
            cout << "YES" << nl;
            row.insert(i);
            col.insert(j);
            up.insert(j+i);
            down.insert(j-i);
        }
    }
    return 0;
}

int main(){
    FASTIO
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}