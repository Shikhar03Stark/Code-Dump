#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

ll mod = 1e9 + 7;

int solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n+1, 0);
    vector<int> hist(n+1);
    vector<tuple<int,int,int>> range(k);
    for(int i = 0; i<k; i++){
        cin >> get<0>(range[i]) >> get<1>(range[i]) >> get<2>(range[i]);
        int mid = (get<0>(range[i]) + get<1>(range[i]))/2;
        arr[mid] = get<2>(range[i]);
    }
    for(auto& e: arr){
        cerr << e << " ";
    }
    cerr << endl;
    int x = 0;
    int zeros = 0;
    for(int i = 1; i<=n; i++){
        if(arr[i] == 0) zeros++;
        x = (x^arr[i]);
    }

    ll ans = 1;
    for(int i = 0; i<zeros; i++){
        ans = (ans*2)%mod;
    }
    cout << (ans*x)%mod << endl;
    return 0;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}