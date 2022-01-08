#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        unsigned ll a, b;
        cin >> a >> b;
        if ( a % 2 == 1 && b % 2 == 1){
            cout << a*b - a*(b/2) - b*(a/2) + 2*(a/2)*(b/2) << endl;
        }
        else{
            cout << a*b/2 << endl;
        }
    }
    return 0;
}