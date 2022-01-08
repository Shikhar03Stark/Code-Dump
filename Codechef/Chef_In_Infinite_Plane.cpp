#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int main(){
    FASTIO
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(auto& e: arr){
            cin >> e;
        }

        set<pair<int,int>> S;
        for(int i = 0; i<n; i++){
            int prev = S.size();
            int x = 1, y = arr[i]-1;
            while(S.size() == prev && x > 0 && y > 0 && x <= arr[i]/2){
                S.insert({x, arr[i]-x});
                x++;
            }
        }

        cout << S.size() << endl;
    }
    return 0;
}