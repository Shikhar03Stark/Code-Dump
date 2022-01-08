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
        int s;
        cin >> s;
        if(s == 1){
            cout << 1 << endl;
            continue;
        }

        if(s == 2){
            cout << 2 << endl;
            continue;
        }

        int len = 2;
        while(len*len < s){
            len++;
        }
        cout << len << endl;
    }
    return 0;
}