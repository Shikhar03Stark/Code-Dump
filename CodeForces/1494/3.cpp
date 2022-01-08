#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int solve(vector<int>& box, vector<int>& rew, int b, int r){
    if(b >= 0 && r >= 0){
        if(box[b] == rew[r]){
            return 1 + solve(box, rew, b-1, r-1);
        }
        if(box[b] > rew[r]){
            return 0 + solve(box, rew, b-1, r);
        }
        else{
            int mc = b+1;
            int count = 1;
            for(int k = r-1; k>r-mc && k >= 0; k--){
                if(rew[k+1] - rew[k] == 1){
                    count++;
                }
                else{
                    break;
                }
            }
            int a2 = solve(box, rew, b, r-1);
            int a3 = solve(box, rew, b-1, r);

            return max({count, a2, a3});
        }
    }
    return 0;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> box(n), rewards(m);
        for(auto& b : box){
            cin >> b;
        }
        for(auto& r: rewards){
            cin >> r;
        }

        vector<int> posb, negb, posr, negr;
        int index = lower_bound(box.begin(), box.end(), 0) - box.begin();
        for(int i = index ;i <box.size(); i++){
            posb.push_back(box[i]);
        }
        for(int i = index-1; i>=0; i--){
            negb.push_back(-box[i]);
        }

        index = lower_bound(rewards.begin(), rewards.end(), 0) - rewards.begin();
        for(int i = index ;i <rewards.size(); i++){
            posr.push_back(rewards[i]);
        }
        for(int i = index-1; i>=0; i--){
            negr.push_back(-rewards[i]);
        }

        int tot = solve(posb, posr, posb.size()-1, posr.size()-1) + solve(negb, negr, negb.size()-1, negr.size()-1);

        cout << tot << endl;


    }
    return 0;
}