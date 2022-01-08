#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long 

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ull n;
        cin >> n;
        ull t = n;
        ull sum = 0;
        do{
            t=n;
            sum = 0;
            while(t){
                sum += t%10;
                t /= 10;
            }
        }while(__gcd(n++,sum) == 1);
        cout << n-1 << endl;
    }
    return 0;
}