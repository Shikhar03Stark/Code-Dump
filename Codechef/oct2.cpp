#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int main(){
    FASTIO
    int t;
    cin>>t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        vector<ll> queries(n);
        for(auto &q : queries){
            cin >> q;
        }

        ll day = 0;
        bool zeroday = false;
        for(int i = 0; i<queries.size()-1; i++){
            ++day;
            if(queries[i] - k*(i+1) < 0){
                zeroday = true;
                cout << day << endl;
                break;
            }
            queries[i+1] += queries[i];
        }
        if(!zeroday && queries[queries.size()-1] - k*(queries.size()) < 0 ){
            cout << n << endl;
            zeroday = true;
        }

        if(!zeroday){
            cout << queries[queries.size()-1]/k + 1 << endl;
        }
    }
    return 0;
}