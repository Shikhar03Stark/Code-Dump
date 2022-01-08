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
        ll n;
        cin >> n;
        if(n >= 9){
            cout << 1 + (n-9)/10 << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
    return 0;
}