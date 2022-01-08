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
        unordered_map<char,int> h;
        string seq;
        cin >> seq;
        for(int i = 0; i<26; i++){
            h[seq[i]] = i;
        }
        string word;
        cin >> word;
        int ans = 0;
        for(int i = 1; i<word.size(); i++){
            ans += abs(h[word[i]] - h[word[i-1]]);
        }
        cout << ans << endl;

    }
    return 0;
}