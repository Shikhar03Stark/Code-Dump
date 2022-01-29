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
    vector<int> marks(n);
    for(auto& e: marks){
        cin >> e;
    }
    sort(marks.begin(), marks.end());
    double sum = 0;
    for(int i = 0; i<n; i++){
        sum += marks[i];
    }
    int i = 0;
    while(sum/n < 4.5 && i<n){
        sum += 5 - marks[i++];
    }
    cout << i << nl;
    return;
}

int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}