// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    int ops = 0;
    while(!is_sorted(arr.begin(), arr.end())){
        for(int i = (ops%2); i+1<n; i+=2){
            if(arr[i] > arr[i+1]){
                swap(arr[i], arr[i+1]);
            }
        }
        ops++;
    }

    cout << ops << nl;
    return;
}

int main(){
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}