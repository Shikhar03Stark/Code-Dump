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
        string after = s;
        sort(begin(after), end(after));
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(after[i] != s[i]){
                cnt++;
            }
        }
        cout << cnt << endl;    
    }
    return 0;
}