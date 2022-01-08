#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

bool isSub(string a, string b){
    int j = 0;
    for(int i = 0; i<a.size(); i++){
        while(j<b.size() && a[i] != b[j]) j++;
        if(j == b.size()) return false;
        j++;
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        if(n == 0 || n == 1){
            cout << "NO" << endl;
            continue;
        }
        if(n%2 == 0){
            bool isd = true;
            for(int i = 0; i<n/2; i++){
                if(s[i] != s[i+n/2]){
                    isd = false;
                    break;
                }
            }
            cout << (isd?"YES":"NO") << endl;
        }
        else{
            int h = n/2;
            bool poss = isSub(s.substr(0, h), s.substr(h)) || isSub(s.substr(h+1), s.substr(0, h+1));
            cout << (poss?"YES":"NO") << endl;
        }
    }
    return 0;
}