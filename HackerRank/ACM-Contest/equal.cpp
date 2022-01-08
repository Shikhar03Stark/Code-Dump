#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(auto &e : arr){
        cin >> e;
    }

    ll sum = 0;
    for(auto &e : arr){
        sum += e;
        sum %= arr.size();
    }

    if(sum == 0){
        cout << n << endl;
    }
    else{
        cout << n-1 << endl;
    }

    return 0;
}