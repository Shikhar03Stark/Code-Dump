#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

bool isPrime(int x){
    if(x == 2){
        return true;
    }
    if(x == 3){
        return true;
    }

    for(int i = 2; i*i<=x; i++){
        if(x%i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int l, r;
        cin >> l >> r;
        int p = r+1;
        for(;p<=2*1000000000; p++){
            if(isPrime(p)){
                cout << p << endl;
                break;
            }
        }
    }
    return 0;
}