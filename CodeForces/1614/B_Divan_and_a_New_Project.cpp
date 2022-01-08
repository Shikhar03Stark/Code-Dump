#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    int n;
    cin >> n;
    vector<pair<ll,ll>> arr(n);
    int i=0;
    for(auto& e: arr){
        int d;
        cin >> d;
        e = {d,i++};
    }
    sort(arr.rbegin(), arr.rend());
    ll tot = 0;
    for(int i = 0; i<n; i+=2){
        if(i<n){
            tot += 2*((i+2)/2)*arr[i].first;
            arr[i].first = (i+2)/2;
            arr[i] = {arr[i].second, arr[i].first};
        }
        if(i+1<n){
            tot += 2*((i+2)/2)*arr[i+1].first;
            arr[i+1].first = -(i+2)/2;
            arr[i+1] = {arr[i+1].second, arr[i+1].first};
        }
    }
    sort(arr.begin(), arr.end());
    cout << tot << endl;
    cout << 0 << ' ';
    for(int i = 0; i<n; i++){
        cout << arr[i].second << " ";
    }
    cout << endl;

    return 0;
}

int main(){
    FASTIO
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}