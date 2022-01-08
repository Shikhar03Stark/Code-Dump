#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

class Solution {

public : 

        bool isPalindrome(string s){
        int i = 0, j=s.size()-1;
        bool res = true;
        while(i<j){
            if(s[i] != s[j]){
                res = false;
                break;
            }
            ++i;
            --j;
        }
        return res;
    }
    
    string solve(string s){
        if(s.size()<=1){
            return s;
        }
        else{
            if(isPalindrome(s)){
                return s;
            }
            else{
                string a1,a2;
                for(int i = 1; i<s.size(); i++){
                    if(isPalindrome(s.substr(i,s.size()))){
                        a1 = s.substr(i,s.size());
                        break;
                    }
                }
                
                a2 = solve(s.substr(0, s.size()-1));
                return (a1.size()>a2.size()) ? a1 : a2;
            }
        }
    }
    
    string longestPalindrome(string s) {
        return solve(s);
    }
};

int main(){
    Solution sol;
    string s = sol.longestPalindrome("abcdbbfcba");
    cout << s << endl;

    return 0;
}
