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
        int n = s.size();
        int cnt = 0;
        bool pos = true;
        for(int i = 0; i<n; i++){
            if(s[i] == '1') cnt++;
        }

        cout << (cnt%2 == 1?"WIN":"LOSE") << endl;
    }
    return 0;
}