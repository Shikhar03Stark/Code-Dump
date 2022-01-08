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
        ull l, r;
        cin >> l >> r;
        ull lm = l/3UL, rm = r/3UL;
        if(l%3==0 && r%3 == 0){
            cout << rm-lm+1 << endl;
        }
        else if(l%3 != 0 && r%3 == 0){
            cout << rm-lm << endl;
        }
        else if(l%3 == 0 && r%3 != 3){
            cout << rm-lm+1 << endl;
        }
        else{
            cout << rm-lm << endl;
        }


    }
    return 0;
}