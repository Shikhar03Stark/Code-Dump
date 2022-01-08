#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        set<ll> S;
        ll length;
        for(int i = 0; i<n; i++){
            cin >> length;
            S.insert(length);
        }

        cout << S.size() << endl;
    }
    return 0;
}