#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

class Solution {

public : 

        string solve(string in, int idx){
        if(idx >= in.size()){
            return "";
        }
        string output = "";
        int move = 0;
        if(in[idx] >= '0' && in[idx]<='9'){
            //number encountered
            int len = 0;
            while(in[idx+len] >= '0' && in[idx+len] <= '9'){
                len++;
            }
            
            int num = stoi(in.substr(idx, len));
            
            int opB = idx+len;
            len = 1;
            while(opB+len < in.size() && in[opB+len] != ']'){
                len++;
            }
            
            string nested = in.substr(opB+1,len-1);
            string result = solve(nested, 0);
            string out = "";
            for(int i = 0; i<num; i++){
                out += result;
            }
            output += out;
            move = opB + len+1;
        }
        
        while(move < in.size() && in[move]  > '9'){
            if (in[move] != ']' || in[move] != '[')
                output.push_back(in[move]);
            move++;
        }
        if(move<in.size()){
            return output+solve(in.substr(move, 100), 0);
        }
        else
            return output;
        
    }
    
    string decodeString(string s) {
       return solve(s, 0);
    }
};

int main(){
    Solution sol;
    string ans = sol.decodeString("3[a2[c]]");
    cout << ans << endl;
    return 0;
}
