#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

class Solution {

public : 

        int reverse(int x) {
        int len = 0;
        int temp = x;
        while(temp){
            temp /= 10;
            len++;
        }
        
        if(len < 10){
            int isNeg = (x < 0) ? -1 : 1;
            string org = to_string(abs(x));
            std::reverse(org.begin(), org.end());
            int rev = stoi(org);
            return isNeg*rev;
        }
        else if(len == 10){
            int isNeg = (x < 0) ? -1 : 1;
            string org = to_string(abs(x));
            if(isNeg == -1){
                string mini = to_string(INT_MAX+1);
                mini.erase(mini.begin());
                std::reverse(org.begin(), org.end());
                if(mini < org){
                    return 0;
                }
                else{
                    return isNeg*(stoi(org));
                }
            }
            else{
                string mini = to_string(abs(INT_MAX));
                std::reverse(org.begin(), org.end());
                if(mini < org){
                    return 0;
                }
                else{
                    return stoi(org);
                }
            }
        }
        else{
            return 0;
        }
        
        return 0;
    }
    
};

int main(){
    Solution sol;
    cout << sol.reverse(-2147483412) << endl;

    return 0;
}
