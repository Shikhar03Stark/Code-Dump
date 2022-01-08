#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

class Solution {

public : 

        
    int find(vector<int>& dsu, int i){
        return (dsu[i] < 0)?i:dsu[i] = find(dsu, dsu[i]);
    }
    
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        //vector<vector<int>> graph(n, vector<int>());
        vector<int> dsu(n, -1);
        for(auto e: allowedSwaps){
            int i = find(dsu, e[0]), j = find(dsu, e[1]);
            if(i != j ){
                if(dsu[i] > dsu[j]){
                    swap(i,j);
                }
                dsu[i] += dsu[j];
                dsu[j] = i;
            }
        }
        
        unordered_map<int, int> mp;
        for(int i = 0; i<target.size(); i++){
            mp[target[i]] = i;
        }
        
        for(int i = 0; i<n; i++){
            if(i != mp[source[i]]){
                if(find(dsu, i) == find(dsu, mp[source[i]])){
                    swap(source[i], source[mp[source[i]]]);
                    i--;
                }
            }
        }
        
        int dist = 0;
        for(int i = 0; i<n ; i++){
            dist += (source[i] != target[i])?1:0;
        }
        
        return dist;
        
    }
};

int main(){
    vector<int> source = {5,1,2,4,3}, target = {1,5,4,2,3};
    vector<vector<int>> swaps = {
        {0,4},
        {4,2},
        {1,3},
        {1,4}
    };
    Solution sol;
    int res = sol.minimumHammingDistance(source, target, swaps);
    cout << res << endl;
    return 0;
}