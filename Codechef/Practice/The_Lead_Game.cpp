#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int main(){
        int n;
        cin >> n;
        vector<pair<int,int>> arr(n);
        for(auto& p: arr){
            cin >> p.first >> p.second;
        }
        int max1 = 0, max2 = 0;
        max1 = max(max1, arr[0].first - arr[0].second);
        max2 = max(max2, arr[0].second - arr[0].first);
        for(int i = 1; i<n; i++){
            arr[i].first += arr[i-1].first;
            arr[i].second += arr[i-1].second;
            max1 = max(max1, arr[i].first - arr[i].second);
            max2 = max(max2, arr[i].second - arr[i].first);
        }

        if(max1 > max2){
            cout << 1 << " " << max1 << endl;
        }
        else{
            cout << 2 << ' ' << max2 << endl;
        }
    
    return 0;
}