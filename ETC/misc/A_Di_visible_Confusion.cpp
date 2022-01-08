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
        for(auto&e:arr){
            cin >> e;
        }
        bool pos = true;
        for(int i = 0; i<n; i++){
            bool found = false;
            for(int j = 2; j<=i+2; j++){
                if(arr[i]%j){
                    found = true;
                    break;
                }
            }

            pos &= found;
        }
        cout << (pos?"YES":"NO") << endl;
    }
    return 0;
}