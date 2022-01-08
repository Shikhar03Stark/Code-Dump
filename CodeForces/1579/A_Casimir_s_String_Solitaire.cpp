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
        int a = 0, b = 0, c = 0;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == 'A') a++;
            if(s[i] == 'B') b++;
            if(s[i] == 'C') c++;
        }

        if(a+c == b){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}