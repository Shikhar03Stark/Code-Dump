#include <iostream>
typedef unsigned int ui;

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        ui h, p;
        cin >> h >> p;

        while(h > 0 && p > 0){
            h -= p;
            p = p/2;
        }

        if(h == 0){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
    return 0;
}