#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> city(n);
    for(auto& e : city){
        cin >> e;
    }

    int q;
    cin >> q;
    for(int i = 0; i<q; i++){
        int c, k;
        cin >> c >> k;
        int idx = c-1;
        int dist = 0;
        while(k>0 && idx < n){
            if(city[idx] < 0){
                idx = idx + (-city[idx]);
                continue;
            }
            int t = k;
            k = max(0, k-city[idx]);
            dist += (idx-c+1)*city[idx];
            city[idx] = max(0, city[idx]-t);
            if(city[idx] == 0){
                city[idx] == -1;
            }
            idx++;
        }
        int counter = 1;
        for(int i = idx-1; i>=c-1; i--, counter++){
            if(city[i] <= 0){
                city[i] = -counter;
            }
        }

        cout << dist << endl;
    }
    return 0;
}