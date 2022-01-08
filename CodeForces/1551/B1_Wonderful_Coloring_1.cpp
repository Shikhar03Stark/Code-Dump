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
        unordered_map<char, int> h;
        for(int i = 0; i<s.size(); i++){
            h[s[i]]++;
        }

        int dup = 0;
        int uniq = 0;
        for(auto& p : h){
            if(p.second > 1){
                dup++;
            }
            else{
                uniq++;
            }
        }

        int cnt = 0;
        cnt += uniq/2;
        cnt += dup;
        cout << cnt << endl;
    }
    return 0;
}