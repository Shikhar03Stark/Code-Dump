#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int z = 1; z<=t; z++){
        cout << "Case #" << z << ": ";
        ll n, d, c, m;
        cin >> n >> d >> c >> m;
        string s;
        cin >> s;
        int idx = 0;
        bool pos = true;
        for(idx=0; idx<n; idx++){
            if(s[idx] == 'C' && c>0){
                c--;
            }
            else if(s[idx] == 'D' && d>0){
                d--;
                c +=m;
            }
            else{
                break;
            }
        }
        for(;idx<n; idx++){
            if(s[idx] == 'D'){
                pos = false;
                break;
            }
        }

        cout << (pos?"YES":"NO") << endl;
    }
    return 0;
}