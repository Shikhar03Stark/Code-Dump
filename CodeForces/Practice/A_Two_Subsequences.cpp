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
        int minpos = 0;
        for(int i = 0; i<s.size(); i++){
            if(s[i] < s[minpos]){
                minpos = i;
            }
        }
        cout << s[minpos] << " " << s.substr(0, minpos) + s.substr(minpos+1) << endl;
    }
    return 0;
}