#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

class Solution {

public : 
    int maxSum;
    int n;
    int index;
    bool isGood(int mid){
        long long sum = 0;
        //greater
        int t = mid-1;
        for(int i = index+1; i<n; i++){
            sum += max(1, t);
            if(sum > maxSum)
                return false;
            t--;
        }
        //lesser
        t = mid-1;
        for(int i = index-1; i>=0; i--){
            sum += max(1, t);
            if(sum > maxSum)
                return false;
            t--;
        }
        sum += mid;
        if(sum <= maxSum)
            return true;
        return false;
    }
    
    int maxValue(int n, int index, int maxSum) {
        this->maxSum = maxSum;
        this->n = n;
        this->index = index;
        int low = 1;
        int high = 1000000000;
        int mid ;
        while(low<=high){
            mid = low + (high-low)/2;
            if(isGood(mid)){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        
        return high;
    }  
    
};

int main(){
    Solution sol;
    int n, index, maxSum;
    cin >> n >> index >> maxSum;
    cout << sol.maxValue(n, index, maxSum) << endl;
    return 0;
}
