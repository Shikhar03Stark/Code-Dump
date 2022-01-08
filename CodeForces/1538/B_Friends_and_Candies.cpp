#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(auto& e : arr){
            cin >> e;
        }

        int sum = 0;
        for(auto& e : arr){
            sum += e;
        }

        if(sum%n == 0){
            int avg = sum/n;
            int cnt = 0;
            for(auto& e : arr){
                if (e > avg){
                    cnt++;
                }
            }

            cout << cnt << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
    return 0;
}