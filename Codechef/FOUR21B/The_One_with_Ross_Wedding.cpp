#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    int n, p, q;
    cin >> n >> p >> q;
    p = abs(p);
    q = abs(q);
    string s;
    cin >> s;
    int axis = 0;
    bool pos = false;
    vector<int> d(2,0);
    for(int i = 0; i<n; i++){
        if(s[i]=='1'){
            d[axis]++;
        }
        else{
            axis = !axis;
            d[axis]++;
        }
    }

    //assume 0 as X
    int dx = d[0], dy = d[1];
    if(dx>=p && dy>=q){
        int xrem = dx-p, yrem = dy-q;
        if(xrem%2==0 && yrem%2==0){
            pos = true;
        }
    }
    dy = d[0], dx = d[1];
    if(dx>=p && dy>=q){
        int xrem = dx-p, yrem = dy-q;
        if(xrem%2==0 && yrem%2==0){
            pos = true;
        }
    }

    if(pos){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}