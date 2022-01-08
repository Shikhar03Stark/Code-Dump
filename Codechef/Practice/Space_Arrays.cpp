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
        for(int i = 0; i<n; i++){
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());

        vector<bool> done(n+1,false);
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(arr[i] > i+1){
                cnt = -1;
                break;
            }
            else{
                cnt += i+1-arr[i];
            }
        }

        if(cnt%2 == 0 || cnt == -1){
            cout << "Second" << endl;
        }
        else{
            cout << "First" << endl;
        }
    }
    return 0;
}