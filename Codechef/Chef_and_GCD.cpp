#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int minOp(int x, int y){
    if(__gcd(x,y) > 1)
    return 0;
    return 1 + min(minOp(x+1,y), minOp(x, y+1));
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y;
        cin >> x >> y;
        if(__gcd(x,y) > 1){
            cout << 0 << endl;
        }
        else if(__gcd(x+1,y) > 1 or __gcd(x, y+1) > 1){
            cout << 1 << endl;
        }
        else{
            cout << 2 << endl;
        }
    }
    return 0;
}