#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

class Solution {

public : 
     string reverseWords(string s) {
        stack<string> S;
        int i = 0;
        string word = "";
        for(auto &c : s){
            if(c == ' '){
                S.push(word);
                word = "";
            }
            else{
                word.push_back(c);
            }
        }
        
        if(word.size()>0){
            S.push(word);
            word = "";
        }
        
        string rev = "";
        
        while(!S.empty()){
            rev += S.top();
            S.pop();
            rev += " ";
        }
        
        return rev;
    }
};

int main(){
    Solution sol;
    sol.reverseWords("the sky is blue");
}
