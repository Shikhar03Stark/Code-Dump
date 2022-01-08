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
        int n, k;
        cin >> n >> k;
        vector<int> ans(k, 1);
        int x = n-k+3;
        if(x%2==1){
            ans[0] = ans[1] = x/2;
            ans[2] = 1;
        }
        else{
            if(x%4==0){
                ans[0] = x/4;       
                ans[1] = x/4;
                ans[2] = x/2;
            }
            else{
                ans[0] = x/2 - 1;
                ans[1] = x/2 - 1;
                ans[2] = 2;
            }
        }

        for(auto& e: ans){
            cout << e << " ";
        }
        cout << endl;
    }
    return 0;
}