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
        string s;
        cin >>s;
        int n = s.size();
        if(s[0] == s[n-1]){
            cout << s << endl;
        }
        else{
            cout << s.substr(0,n-1)+string(1,s[0]) << endl;
        }
    }
    return 0;
}