#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

class Solution {

public : 

    int minimumSwap(string s1, string s2) {
        if(s1.size() != s2.size()){
            return -1;
        }
        int n = s1.size();
        int xy = 0, yx = 0;
        for(int i = 0; i<n; i++){
            if(s1[i] == 'x' && s2[i] == 'y')
                xy++;
            if(s1[i] == 'y' && s2[i] == 'x')
                yx++;
        }

        int swaps = 0;
        while(xy>1){
            xy -=2;
            swaps++;
        }
        while(yx>1){
            yx -=2;
            swaps++;
        }
        
        if(xy || yx){
            if(xy == 0 && yx != 0){
                return -1;
            }
            if(yx == 0 && xy != 0){
                return -1;
            }
            return swaps+2;
        }
        
        return swaps;
    }
};


int main(){
    Solution sol;
    sol.minimumSwap("xx", "yy");
    return 0;
}