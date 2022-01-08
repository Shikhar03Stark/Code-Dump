#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int boxes(vector<uint> &box, int curr, int leftA, int leftB, map<tuple<ll,ll,ll>, int>& memo){
    if(curr >= box.size() || (leftA <= 0 && leftB <= 0)){
        if(curr == box.size() && !(leftA <= 0 && leftB <= 0)){
            return INT_MIN;
        }
        else{
            return 0;
        }
    }

    if(memo.count({curr, leftA, leftB}) > 0){
        return memo[{curr,leftA, leftB}];
    }
    if(memo.count({curr, leftB, leftA}) > 0){
        return memo[{curr,leftB, leftA}];
    }

    if(leftA > 0 && leftB > 0){
        int resL = boxes(box, curr+1, leftA-box[curr], leftB, memo);
        int resR = boxes(box, curr+1, leftA, leftB-box[curr], memo);
        if(resL < 0 && resR < 0){
            return memo[{curr, leftA, leftB}] = INT_MIN;
        }
        else if(resL < 0){
            return memo[{curr, leftA, leftB}] = 1 + resR;
        }
        else if(resR < 0){
            return memo[{curr, leftA, leftB}] = 1 + resL;
        }
        else{
            return memo[{curr, leftA, leftB}] = 1 + min(resL, resR);
        }
    }

    if(leftB <= 0){
        return memo[{curr, leftA, leftB}] = 1 + boxes(box, curr+1, leftA - box[curr], leftB, memo);
    }

    if(leftA <= 0){
        return memo[{curr, leftA, leftB}] = 1 + boxes(box, curr+1, leftA, leftB - box[curr], memo);
    
    }

    return 0;
}

int solve(vector<uint>& box, int curr, int heightA, int heightB, int k, int memo[][100000][100000]){
    if(heightA>=k && heightB>=k){
        return 0;
    }
    if(curr>=box.size()){
        return INT_MIN;
    }

    if(memo[curr][heightA][heightB] != 0){
        return memo[curr][heightA][heightB];
    }
    if(memo[curr][heightB][heightB] != 0){
        return memo[curr][heightA][heightB];
    }

    if(heightA<k && heightB<k){
        int resL = solve(box, curr+1, heightA+box[curr], heightB, k, memo);
        int resR = solve(box, curr+1, heightA, heightB+box[curr], k, memo);

        if(resL < 0 && resR < 0){
            return memo[curr][heightA][heightB] = INT_MIN;
        }
        else if(resL < 0){
            return memo[curr][heightA][heightB] = 1+resR;
        }
        else if(resR < 0){
            return memo[curr][heightA][heightB] = 1+resL;
        }
        else{
            return memo[curr][heightA][heightB] = 1+min(resL, resR);
        }
    }

    if(heightA>=k){
        //greedy calc for B
        int i = curr;
        int res = 0;
        for(;i<box.size();i++){
            if(heightB>=k){
                break;
            }
            heightB += box[i];
            res++;
        }
        if(heightB>=k){
            return memo[curr][heightA][heightB] = res;
        }
        else{
            return memo[curr][heightA][heightB] = INT_MIN;
        }
    }

    if(heightB>=k){
        //greedy calc for B
        int i = curr;
        int res = 0;
        for(;i<box.size();i++){
            if(heightA>=k){
                break;
            }
            heightA += box[i];
            res++;
        }
        if(heightA>=k){
            return memo[curr][heightA][heightB] = res;
        }
        else{
            return memo[curr][heightA][heightB] = INT_MIN;
        }
        return 0;
    }

    return 0;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin >> n >> k;

        vector<uint> box(n);
        for(auto &e : box){
            cin >> e;
        }

        sort(box.begin(), box.end(), greater<uint>());

        //int memo[box.size()][k*k][k*k];
        //memset(memo, 0, k*k*k*k);
        //int res = solve(box, 0, 0, 0, k, memo);

        map<tuple<ll,ll,ll>, int> memo;
        int res = boxes(box, 0, k, k, memo);

        if(res>=0){
            cout << res << endl;
        }
        else{
            cout << -1 << endl;
        }

        //cout << boxes << endl;
    }
    return 0;
}