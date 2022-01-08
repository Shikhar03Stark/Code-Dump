#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    int c, t;
    cin >> c >> t;
    if(c >= t/2.0){
        cout << "TOP" << endl;
    }
    else if(c < t/4.0){
        cout << "BOTTOM" << endl;
    }
    else{
        cout << "MIDDLE" << endl;
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