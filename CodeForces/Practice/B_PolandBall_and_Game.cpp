#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    int n, m;
    cin >> n >> m;
    map<string,int> h;
    for(int i = 0; i<n; i++){
        string s;
        cin >> s;
        h[s]++;
    }
    for(int i =0; i<m; i++){
        string s;
        cin >> s;
        h[s] += 2;
    }
    int a = 0, b = 0, both = 0;
    for(auto& p: h){
        if(p.second == 1){
            a++;
        }
        if(p.second == 2){
            b++;
        }
        if(p.second == 3){
            both++;
        }
    }

    if((both-both/2+a) > (both/2+b)){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

    return 0;
}

int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}