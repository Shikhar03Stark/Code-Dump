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
        int left = 0, right = s.size()-1;
        int apos = -1;
        int n = s.size();
        for(int i = 0; i<n; i++){
            if(s[n-i-1] != 'a')
                apos = i, i = n;
        }

        if(apos == -1){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            for(int i = 0; i<apos; i++){
                cout << s[i];
            }
            cout << 'a';
            for(int i = apos; i<s.size(); i++){
                cout << s[i];
            }
            cout << endl;
        }
    }
    return 0;
}