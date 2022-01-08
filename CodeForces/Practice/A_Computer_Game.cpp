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
        string a, b;
        cin >> a;
        cin >> b;
        bool pos = true;
        for(int  i = 0; i<n; i++){
            if(a[i] == '1' && b[i] =='1'){
                pos = false;
                break;
            }
        }
        cout << (pos?"YES":"NO")  << endl;
    }
    return 0;
}