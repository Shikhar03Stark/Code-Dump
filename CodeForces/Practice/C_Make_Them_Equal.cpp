#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    int n;
    char c;
    cin >> n >> c;
    string s;
    cin >> s;
    bool hasdiff = false;
    for(int i = 0; i<n; i++){
        if(s[i] != c){
            hasdiff = true;
            break;
        }
    }
    if(hasdiff){
        int afterhalfc = -1;
        for(int i = n/2; i<n; i++){
            if(s[i] == c){
                afterhalfc = i;
            }
        }
        if(afterhalfc >= 0){
            cout << 1 << endl;
            cout << afterhalfc+1 << endl;
        }
        else{
            cout << 2 << endl;
            cout << n-1 << " " << n << endl;
        }
    }
    else{
        cout << 0 << endl;
    }
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