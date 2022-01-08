#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

vector<int> a,b,dp;
int n;
ll solve(ll pos){
    if(pos >= n-1){
        return 0;
    }

    
}

int main(){
    cin >> n;
    dp.resize(n,INT_MAX);
    a.resize(n);
    b.resize(n);
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    for(int i = 0; i<n; i++){
        cin >> b[i];
    }

    ll ans = INT_MAX;
    for(int i = 0; i<n; i++){
        if(a[i] > i){
            ans = min(ans, 1+solve(i));
        }
    }

    if(ans == INT_MAX){
        cout << -1 << endl;
    }
    else{
        cout << ans << endl;
    }
    
    return 0;
}