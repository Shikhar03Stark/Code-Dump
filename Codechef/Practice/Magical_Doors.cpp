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
        cin >> s;
        int flip = 0;
        for(int i = 1; i<s.size(); i++){
            if(s[i-1] != s[i]) flip++;
        }
        cout << (s[0]=='1'?flip:flip+1) << endl;
    }
    return 0;
}