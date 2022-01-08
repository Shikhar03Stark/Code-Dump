#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

class Solution {

public : 

    bool canDo(int o, int time){
        int d = 0;
        while(d<time){
            if(o%3 == 0)
                o /= 3;
            if(o%3 == 1)
                o -= 1;
            else{
                if(o%2 == 0)
                    o /= 2;
                else
                    o -= 1;
            }
            d++;
            if(o==0){
                break;
            }
        }
        
        if(o==0){
            return true;
        }
        return false;
    }
    
    int minDays(int n) {
        int start = 1, end = 2*1000000000, mid;
        while(start <= end){
            mid = start + (end-start)/2;
            if(canDo(n, mid)){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        
        return start;
    }
};

int main(){
    Solution sol;
    cout << sol.minDays(6) << endl;
    return 0;
}
