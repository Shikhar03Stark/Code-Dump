#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> shelf(n);
        for(ll i = 0; i<n; i++){
            cin >> shelf[i];
        }

        bool bookstart = false;
        ll zeros = 0, temp = 0;
        for(ll i = 0; i<n; i++){
            if(bookstart){
                if(shelf[i] == 1){
                    zeros += temp;
                    temp = 0;
                }
                else{
                    temp++;
                }
            }
            else{
                if(shelf[i] == 1){
                    bookstart = true;
                }
            }
        }

        cout << zeros << endl;
    }
    return 0;
}