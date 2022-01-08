#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<int> nums(n);
        for(auto &n: nums){
            cin >> n;
        }

        int inc = 0;
        int dec = 0;
        for(int i = 0; i<n-1; i++){
            if(nums[i] < nums[i+1]){
                ++inc;
            }
            else if(nums[i] > nums[i+1]){
                ++dec;
            }
        }
        if(inc == dec){
            cout << "NO" << endl;
        }
        else if(inc >= dec){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}