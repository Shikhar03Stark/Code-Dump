#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> doms(n);
        for(ll i = 0; i< n; i++){
            cin >> doms[i];
        }

        priority_queue<pair<ll,int>> pQ;
        for(int i = 0; i<n; i++){
            pQ.push({doms[i], i});
        }

        //find ideal fish
        bool isFound = false;
        int index = 0;
        while(!pQ.empty() && !isFound){
            auto fish = pQ.top();
            pQ.pop();

            if(fish.second < n - 1 && fish.first > doms[fish.second + 1]){
                index = fish.second;
                isFound = true;
            }
            else if(fish.second > 0 && fish.first > doms[fish.second - 1]){
                index = fish.second;
                isFound = true;
            }

        }

        if(isFound){
            cout << index+1 << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
    return 0;
}