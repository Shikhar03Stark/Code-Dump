#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll a, b, c;
        cin >> a >> b >> c;
        ll mean = (a+c)/2;
        ll k = abs((a+c-2*b)/3);
        ll lhs = abs(a+c-2*b);
        ll rm = lhs%3;
        if(rm==0){
            cout << 0 << endl;
        }
        else{
            cout << 1 << endl;
        }

    }
    return 0;
}