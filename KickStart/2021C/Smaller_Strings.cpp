#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

const ull mod = 1e9+7;
vector<vector<int>> dp;
ull solve(string& s, int start, char prev, int k){
    int n = s.size();
    if(start > (n+1)/2){
        if(prev < s[start-1]){
            return 1;
        }
        return 0;
    }
    if(dp[start][prev] != -1){

    }
    ull ans = 0;
    if(prev == s[start-1]){
        for(char c = 'a'; c<=s[start]; c++){
            ans += solve(s, start+1, c, k);
        }
        //ans += solve(s, start+1, s[start], k);
    }
    else{
        ans += (k*((n+1)/2 - start));
    }

    return dp[start][prev] = ans;
}

int main(){
    int t;
    cin>>t;
    for(int z = 1; z<=t; z++){
        cout << "Case #" << z << ": ";
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        if(n == 1 || n == 2){
            if(n == 1){
                cout << s[0] - 'a' << endl;
            }
            else if(n == 2){
                ull ans = s[0] - 'a';
                if(s[1] > s[0]){
                    ans++;
                }
                cout << ans << endl;
            }
            continue;
        }
        dp.resize(n, vector<int>(300,-1));
        ull ans = 0;
        for(char c = 'a'; c<=s[0]; c++){
            ans += solve(s, 1, c, k);
        }
        cout << ans << endl;

    }
    return 0;
}