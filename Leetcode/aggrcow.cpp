#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

bool fitting(int dist, vector<int>& stall, int cows){
    int prev = 0;
    int curr = 1;
    cows--;
    while(curr<stall.size()){
        if(stall[curr] - stall[prev]>= dist){
            cows--;
            prev = curr;
        }
        else{
            curr++;
        }
    }

    if(cows <= 0){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, c;
        cin >> n >> c;
        vector<int> stall(n);
        for(auto&e: stall){
            cin >> e;
        }

        //NlogN
        sort(stall.begin(), stall.end());

        int start = 1, end = 1000000000, mid;
        while(start<=end){
            mid = start + (end-start)/2;
            if(fitting(mid, stall, c)){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }

        cout << end << endl;

    }
    return 0;
}