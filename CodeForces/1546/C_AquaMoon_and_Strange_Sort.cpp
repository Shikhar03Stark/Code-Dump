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
    vector<int> arr(n), cp;
    vector<map<int,int>> h(2);
    //int i = 0;
    for(auto &e: arr){
        cin >> e;
        //h[i%2][e]++;
    }
    cp = arr;
    sort(cp.begin(), cp.end());
    int i = 0;
    for(auto &e: cp){
        h[i%2][e]++;
        i++;
    }
    if(is_sorted(arr.begin(), arr.end())){
        cout << "YES" << nl;
    }
    else{
        for(int i = 0; i<n; i++){
            if(h[i%2][arr[i]]>0){
                h[i%2][arr[i]]--;
            }
            else{
                cout << "NO" << nl;
                return;
            }
        }
        cout << "YES" << nl;
    }
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