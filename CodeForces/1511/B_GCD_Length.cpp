#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

ll prime(ll start){
    for(ll i = start; i<=1e9; i++){
        bool isPrime = true;
        for(ll k = 2; k*k<=i; k++){
            if(i%k == 0){
                isPrime = false;
                break;
            }
        }

        if(isPrime){
            return i;
        }
    }

    return -1;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        ll mul = pow(10,c-1);
        a -= c;
        b -= c;
        ll x, y;
        if(a == b){
            //find 2 consective a digit prime
            ll start = pow(10, a);
            ll p1 = prime(start);
            ll p2 = prime(p1+1);
            x = mul*p1;
            y = mul*p2;
            cout << x << " " <<  y << endl;
        }
        else{
            //find first a and b digit prime
            ll p1 = prime(pow(10,a));
            ll p2 = prime(pow(10, b));
            x = mul*p1;
            y = mul*p2;
            cout << mul*p1 << " " << mul*p2 << endl;
        }

        cerr << __gcd(x,y) << endl;
    }
    return 0;
}