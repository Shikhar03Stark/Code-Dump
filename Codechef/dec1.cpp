#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int main(){
    int d1, d2, v1, v2, p;
    cin >> d1 >> v1 >> d2 >> v2 >> p;
    int day = 0;
    while(p > 0){
        if(day >= d1){
            p -= v1;
        }
        if(day >= d2){
            p -= v2;
        }
        ++day;
    }

    cout << day-1 << endl;

    return 0; 
}