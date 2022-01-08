#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

class Solution {

public : 

    int numSplits(string s) {
        vector<int> ld(s.size()-1, 0);
        vector<int> rd(s.size()-1, 0);
        
        unordered_map<char,int> ls, rs;
        for(int i = 0; i<s.size()-1;i++){
            if(ls.count(s[i]) == 0){
                if(i == 0){
                    ld[i]++;    
                }
                else{
                    ld[i] = ld[i-1] + 1;
                }
                
                ls[s[i]]++;
            }
            else{
                ld[i] = ld[i-1];
            }
        }

        reverse(s.begin(), s.end());
        
        for(int i = 0; i<rd.size(); i++){
            int index = rd.size() - i -1;
            if(rs.count(s[i]) == 0){
                if(index == rd.size()-1){
                    rd[index]++;
                }
                else{
                    rd[index] = rd[index+1] + 1;
                }
                rs[s[i]]++;
            }
            else{
                rd[index] = rd[index+1];
            }
        }
        
        int count = 0;
        for(int i = 0; i<ld.size(); i++){
            if(ld[i] == rd[i]){
                count++;
            }
        }
        
        return count;
    }
};

int main(){
    Solution sol;
    int ans = sol.numSplits("aacaba");
    cout << ans << endl;
    return 0;
}
