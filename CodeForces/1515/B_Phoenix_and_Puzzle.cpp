#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

bool solve(ll n){
    if(n%2 == 1){
        return false;
    }
    else{
        ll temp = n/2;
        if(floor(0.5*log2(temp)) == ceil(0.5*log2(temp))){
            return true;
        }
        if(floor(0.5*log2(n)) == ceil(0.5*log2(n))){
            return true;
        }
        return false;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ull n;
        cin >> n;
        if(n <= 1){
            cout << "NO" << endl;
            continue;
        }
        if((n&(n-1)) == 0){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}