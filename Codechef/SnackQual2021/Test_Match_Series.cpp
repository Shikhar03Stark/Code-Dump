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
        int ind = 0, eng = 0;
        for(int i = 0 ;i<5; i++){
            int data;
            cin >> data;
            if(data == 1) ind++;
            if(data == 2) eng++;
        }
        if(ind > eng){
            cout << "INDIA" << endl;
        }
        else if(eng > ind){
            cout << "ENGLAND" << endl;
        }
        else{
            cout << "DRAW" << endl;
        }
    }
    return 0;
}