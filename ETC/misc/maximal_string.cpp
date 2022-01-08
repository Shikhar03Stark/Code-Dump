#include <bits/stdc++.h>
using namespace std;

string solv(string A, int B, int start){
    int n = A.size();
    if(start >= n){
        return A;
    }
    if(B <= 0){
        return A;
    }
    int maxi = start;
    string ans = A;
    for(int i = start; i<n; i++){
        if(A[maxi] <= A[i]){
            maxi = i;
            if(maxi == start){
                string br = solv(A, B, start+1);
                if(ans < br){
                    ans = br;
                }
            }
            else{
                swap(A[maxi], A[start]);
                string br = solv(A, B-1, start+1);
                if(ans < br){
                    ans = br;
                }
                else{
                    swap(A[maxi], A[start]);
                    string br = solv(A, B, start+1);
                    if(ans < br){
                        ans = br;
                    }
                }
            }
        }
    }



    return ans;
}

int main(){
    string s = "253";
    cout << solv(s, 2, 0) << endl;

    return 0;
}