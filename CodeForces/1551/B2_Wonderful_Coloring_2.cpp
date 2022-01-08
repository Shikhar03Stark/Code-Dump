#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

struct elem{
    int idx;
    int val;
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<elem> nums(n);
        for(int i = 0; i<n; i++){
            cin >> nums[i].val;
            nums[i].idx = i;
        }

        auto comp = [](elem a, elem b){
            return a.val < b.val;
        };
        sort(begin(nums), end(nums), comp);
        int colour = 1;
        vector<int> ans(n,0);
        for(int i = 0; i<n; i++){
            
        }
        


    }
    return 0;
}