#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

long frogSort(vector<vector<int>> &frog){
    int res = 0;
    for(int i = frog.size()-1; i>0;i--){
        auto curr = frog[i];
        auto prev = frog[i-1];
        res = 0;
        if(curr[0] <= prev[0]){
            //reorder
            int t = ceil((prev[0] + 1.0 - curr[0])/curr[2]);
            //update curr
            frog[i][0] = frog[i][0] + t*frog[i][2];
            return t + frogSort(frog);
        }
    }

    return 0;
}

auto comp = [](vector<int> a, vector<int> b){
    return (a[1] < b[1]);
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> frog(n, vector<int>(3,0)); //pos, w, L
        for(int i = 0; i<n; i++){
            //weight
            cin >> frog[i][1];
            //pos
            frog[i][0] = i;
        }
        for(int i = 0; i<n; i++){
            //L
            cin >> frog[i][2];
        }
        sort(frog.begin(), frog.end(), comp);

        long jumps = frogSort(frog);


        cout << jumps << endl;
    }
    return 0;
}