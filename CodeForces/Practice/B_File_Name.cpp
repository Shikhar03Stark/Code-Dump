#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int state = 1;
    int del = 0;
    int cnt = 0;
    for(int i = 0; i<n; i++){
        if(state == 1){
            if(s[i] == 'x'){
                state = 2;
                cnt = 1;
            }
        }
        else if(state == 2){
            if(s[i] != 'x'){
                state = 1;
                cnt=0;
            }
            else{
                cnt++;
                if(cnt >= 3){
                    del++;
                }
            }
        }
    }
    cout << del << endl;
    return 0;
}

int main(){
    solve();
    return 0;
}