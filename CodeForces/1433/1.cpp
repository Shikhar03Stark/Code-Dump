#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll x;
        cin >> x;

        ll temp = x;
        int dig = 0;
        while(temp){
            temp /= 10;
            dig++;
        }
        int ones = x%10;
        cout << ((ones-1)*10) + (dig*(dig+1)/2) << endl;
    }
    return 0;
}