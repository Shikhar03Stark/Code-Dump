#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

bool issorted(string &s){
    for(int i = 1; i<s.size(); i++){
        if(s[i]<s[i-1]) return false;
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        if(is_sorted(s.begin(), s.end())){
            cout << 0 << endl;
            continue;
        }
        string t = s;
        sort(t.begin(), t.end());
        vector<int> idx;
        for(int i = 0; i<n; i++){
            if(s[i] != t[i]){
                idx.push_back(i);
            }
        }
        cout << 1 << endl;
        cout << idx.size() << " ";
        for(int i = 0; i<idx.size(); i++){
            cout << idx[i]+1 << " ";
        }
        cout << endl;
    }
    return 0;
}