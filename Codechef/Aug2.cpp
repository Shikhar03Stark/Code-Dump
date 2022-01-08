#include <iostream>
#include <climits>
#include <vector>
#include <utility>

typedef long unsigned int lui;
typedef long int li;

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        lui n, k;
        cin >> n >> k;
        vector<lui> P(n);
        pair<int, int> min;
        min.first = INT_MAX;
        min.second = -1;
        for(auto &p: P){
            cin >> p;
        }

        for(int i = 0; i<P.size(); i++){
            if(k > P[i] && k % P[i] == 0){
                if (k/P[i] < min.first){
                    min.first = k/P[i];
                    min.second = i;
                }
            }
        }

        if(min.first == INT_MAX){
            cout << -1 << endl;
        }
        else{
            cout << min.second + 1 << endl;
        }

    }
    return 0;
}