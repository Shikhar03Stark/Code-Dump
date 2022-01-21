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
    for(auto& e: arr){
        cin >> e;
    }
    int a = *min_element(arr.begin(), arr.end());
    int b = *max_element(arr.begin(), arr.end());
    int ans = b-a;
    cout << ans << " ";
    if(ans==0){
        ll na = count(arr.begin(), arr.end(), a);
        cout << (na*(na-1))/2 << nl;
    }
    else{
        ll na = count(arr.begin(), arr.end(), a);
        ll nb = count(arr.begin(), arr.end(), b);
        cout << na*nb << nl;
    }
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