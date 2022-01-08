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
        string s;
        cin >> s;
        ll len = 1e8;
        for(int i = 0; i<n; i++){
            map<char,int> h;
            for(int j = i; j<min(i+8, n); j++){
                h[s[j]]++;
                if(j-i+1>=2 && h['a']>h['b'] && h['a']>h['c']){
                    len = min(len, (ll)j-i+1);
                }
            }
        }

        cout << (len==1e8?-1:len) << endl;
    }
    return 0;
}