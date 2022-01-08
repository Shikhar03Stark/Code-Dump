#include <bits/stdc++.h>
#include <experimental/random>
using namespace std;

void inc(uint n, long int l, long int h){
    bool decrease = false;
    cout << n << "\n";
    for(uint i = 0; i<n ;i++){
        if(!decrease){
            cout << l << " ";
        }
        else{
            l -=2;
            cout << l << " ";
        }
        if(++l >= h){
            decrease = true;
        }
    }
}


int main(){
    inc(10000000, 1, 90909);
    return 0;
}