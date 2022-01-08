#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " = " << x << endl
using namespace std;

int main(){
    
    int x = 12;
    cout << sizeof(x) << endl;
    while(x) {
        int d = x%10;
        x /= 10;
        cout << d;
    }
    cout << endl;
    return 0;
}