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
        int n;
        string s;
        cin >> n;
        cin >> s;
        vector<ull> changes(n, 0);
        ull sum = 0;
        ull mod = 1e9+7;
        for(int start = 0; start<n; start++){
            ull swt = 0;
            char prev = 0;
            for(int i = start; i<n; i++){
                char c = s[i];
                if(c == 'X' || c == 'O'){
                    if(prev == 0){
                        prev = c;
                    }
                    else{
                        if(prev != c){
                            swt++;
                        }
                        prev = c;
                    }
                }
                sum  = (sum%mod + swt%mod)%mod;
            }
        }
        cout << sum << endl;
    }
    return 0;
}