#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

class Solution {

public : 

        int minimumLength(string s) {
        int start = 0,  end = s.size()-1;
        while(end>=start){
            if(s[start] != s[end]){
                break;
            }
            char c = s[start];
            while(s[start] == c && start <= end){
                start++;
            }
            while(s[end] == c && start <= end){
                end--;
            }
        }
        
        return (end-start+1);
    }
};

int main(){
    Solution sol;
    sol.minimumLength("bbbbbbbbbbbbbbbbbbbbbbbbbbbabbbbbbbbbbbbbbbccbcbcbccbbabbb");
}
