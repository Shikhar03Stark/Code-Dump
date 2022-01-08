#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

class Solution {

public : 

    void solve(int rem,string aux, set<string>& sol){
        if(rem == 1){
            sol.insert(aux);
            return;
        }
        string s1 = "()" + aux;
        string s2 = "(" + aux + ")";
        string s3 = aux + "()";
        if(s1 != s3){
            solve(rem-1, s1, sol);
            solve(rem-1, s2, sol);
            solve(rem-1, s3, sol);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        set<string> sol;
        solve(n, "()", sol);
        vector<string> ans;
        for(auto& e : sol){
            ans.push_back(e);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    auto v = sol.generateParenthesis(3);
    for(auto& s: v){
        cout << s << endl;
    }
    return 0;
}
