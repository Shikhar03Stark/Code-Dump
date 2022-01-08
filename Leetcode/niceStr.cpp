#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

class Solution {

public : 

        bool isNice(int start, int end, string& s){
        unordered_map<char,int> h;
        for(int i = start; i<=end; i++){
            if(h.count(s[i]) == 0){
                h[s[i]] = i;
            }
        }
        
        for(int i = start; i<=end; i++){
            char c = s[i];
            if(c >= 'a' && c <= 'z'){
                char other = c - 'a' + 'A';
                if(h.count(other) == 0){
                    return false;
                }
            }
            else if(c >= 'A' && c <= 'Z'){
                char other  = c -'A' + 'a';
                if(h.count(other) == 0){
                    return false;
                }
            }
        }
        return true;
    }
    
    string longestNiceSubstring(string s) {
        int n = s.size();

        for(int i = 0; i<n; i++){
            
            for(int j = i+1; j<n; j++){
                if(isNice(i,j,s)){
                    return s.substr(i,j-i+1);
                }
            }
        }
        
        
        return "";
    }
};

int main(){

    Solution sol;
    cout << sol.longestNiceSubstring("YazaAay") << endl;
}
