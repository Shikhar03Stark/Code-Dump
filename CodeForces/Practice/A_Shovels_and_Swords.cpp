#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    int a, b;
    cin >> a >> b;
    int cnt = 0;
    if(a<b){
        swap(a,b);
    }
    if(a>0 && b>0){
        if(a/2 > b){
            cnt = b;
        }
        else{
            cnt = max({a/2, b/2, (a+b)/3});
        }
    }
    cout << cnt << endl;
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