#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int solve(string& s, string& t, int sl, int sr, int tl, int tr){
    if(tl == tr){
        int idx = s.substr(sl+1, sr-sl-1).find(t[tl]);
        return max(idx+1, sr-sl - idx - 1);
    }
    if(tr-tl<=0)
        return sr-sl;
    
    int l = s.substr(sl+1, sr-sl-1).find(t[tl]);
    int r = s.substr(sl+1, sr-sl-1).rfind(t[tr]);
    return solve(s, t, l+sl+1, sr-sl-r-1, tl+1, tr-1);
}

int main(){
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s;
    cin >> t;
    int left = s.find(t[0]);
    int right = s.rfind(t[t.size()-1]);

    cout << solve(s, t, left, right, 1, t.size()-2) << endl;
    return 0;
}