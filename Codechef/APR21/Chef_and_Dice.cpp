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
        int n;
        cin >> n;
        if(n<4){
            if(n == 1){
                cout << 20 << endl;
            }
            if(n == 2){
                cout << 36 << endl;
            }
            if(n == 3){
                cout << 51 << endl;
            }
            continue;
        }
        int repLayer = max(0, (n-n%4)/4);
        ull pips = 44*repLayer;

        if(n%4 == 1){
            pips += 32;
        }
        else if(n%4 == 2){
            pips += 44;
        }
        else if(n%4 == 3){
            pips += 55;
        }
        else if(n%4 == 0){
            pips += 16; 
        }

        cout << pips << endl;
    }
    return 0;
}