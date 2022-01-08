#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

class Solution {

public : 

    string minWindow(string s, string t) {
        unordered_map<char, int> instr;
        for(auto& c : t){
            instr[c]++;
        }
        
        unordered_map<char, int> h;
        int i = 0; 
        int j = 0;
        int n = s.size();
        bool extend = true;
        string window = s;
        while(j < n){
            if(extend){
                char c = s[j];
                bool over = true;
                if(instr.count(c) != 0){
                    h[c]++;
                    for(auto& ch: instr){
                        if(instr[ch.first] > h[ch.first]){
                            over = false;
                            break;
                        }
                    }
                    if(over){
                        window = (j-i+1) < window.size() ? s.substr(i,j+1) : window;
                        extend = !extend;
                        continue;
                    }
                }
                ++j;
            }
            else{
                if(i == j){
                    extend = !extend;
                    h[s[j]]--;
                    j++;
                    i=j;
                    continue;
                }
                char c = s[i];
                bool over = true;
                if(h.count(c) != 0){
                    for(auto& ch: instr){
                        if(instr[ch.first] > h[ch.first]){
                            over = false;
                            break;
                        }
                    }
                    h[c]--;
                    if(over){
                        window = s.substr(i,j+1).size() < window.size() ? s.substr(i,j+1) : window;
                        extend = !extend;
                    }
                }
                ++i;
            }
        }
        
        return window;
    }
};

int main(){
    Solution sol;
    string ans = sol.minWindow("aa", "aa");
    cout << ans << endl;
    return 0;
}