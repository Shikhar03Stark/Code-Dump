#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin >> s;
        int mex = INT_MAX;
        int has1 = 0, has0 = 0;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '1'){
                has1 = 1;
            }
            else{
                has0 = 1;
            }
        }
        if(has1 && has0){
            mex = min(mex, 2);
        }
        if(has1 && !has0){
            mex = min(mex, 0);
        }
        if(has0 && !has1){
            mex = min(mex, 1);
        }
        int cnt = 0;
        bool inzero = false;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '0' && !inzero){
                cnt++;
                inzero = true;
            }
            if(s[i]=='1'){
                inzero = false;
            }
        }
        cerr << cnt << endl;
        mex = min(mex, cnt);
        cout << mex << endl;
    }
    return 0;
}