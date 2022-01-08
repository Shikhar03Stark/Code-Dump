#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        pair<int,int> stove = {0,0};
        int n;
        cin >> n;
        vector<int> times(n);

        for (auto &e : times){
            cin >> e;
        }

        int tot_time = 0;
        sort(times.begin(), times.end(), greater<int>());

        int dish = 0;
        do{
            if(stove.first == 0 && dish < n){
                stove.first = times[dish];
                ++dish;
            }
            if(stove.second == 0 && dish < n){
                stove.second = times[dish];
                ++dish;
            }

            int time = (stove.first == 0 || stove.second == 0) ? max(stove.first, stove.second): min(stove.first, stove.second);
            tot_time += time;
            stove.first -= time;
            stove.second -= time;
        }while (dish < n || !(stove.first <= 0 && stove.second <= 0));

        cout << tot_time << endl;

    }
    return 0;
}