#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k, x, y;
        cin >> n >> k >> x >> y;

        unordered_map<int, bool> city;
        for(int i = 0; i< n; i++){
            if(i == x){
                city[i] = true;
            }
            city[i] = false;
        }

        int curr = (x+k)%n;
        while(city[curr] == false && curr != y){
            city[curr] = true;
            curr = (curr+k)%n;
        }

        if(curr == y){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}