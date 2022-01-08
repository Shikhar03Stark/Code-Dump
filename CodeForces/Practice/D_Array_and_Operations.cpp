// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    sort(arr.begin(), arr.end());
    int score = 0;
    for(int i = 0; i<n-2*k; i++){
        score += arr[i];
    }

    for(int i = 0; i<k; i++){
        score += arr[n-2*k+i]/arr[n-k+i];
    }

    cout << score << nl;
    return 0;
}

int main(){
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}