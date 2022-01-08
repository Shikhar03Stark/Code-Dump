#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> arr, int n, int k){
    if(n%k == 0){
        vector<int> grp(n, -1);
        int g = 1;
        for(int start = 0; start<n; start++){
            unordered_map<int,int> freq;
            int cnt = 0;
            if(grp[start] < 0){
                for(int i = start; i<n && cnt<k; i++){
                    if(grp[i] < 0 && freq[arr[i]] == 0){
                        grp[i] = g;
                        freq[arr[i]]++;
                        cnt++;
                    }
                }
                if(cnt < k){
                    return false;
                }
                g++;
            }
        }

        return true;
    }
    return false;
}

int main(){

    cout << solve({6,2,3,4,4,6}, 6, 3) << endl;
    
}