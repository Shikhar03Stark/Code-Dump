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
        string s, p;
        cin >> s;
        cin >> p;
        int cnt = 0;
        for(int i = 0; i<n; i++){
            cnt += p[i] - '0';
        }

        if(cnt == 0 || cnt == n){
            if(s == p){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
        else{
            cout << "YES" << endl;
        }
    }
    return 0;
}