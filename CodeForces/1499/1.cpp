#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k1, k2;
        cin >> n>> k1 >> k2;
        int w, b;
        cin >> w >> b;
        bool possible = true;
        int whites = min(k1,k2) + abs(k2-k1)/2;
        possible &= whites >= w;
        
        int balcks = min(n-k1, n-k2) + abs(k2-k1)/2;
        possible &= balcks >= b;

        if(possible){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}