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
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        bool pos = false;
        ll sum = 0;
        for(auto& e : arr){
            cin >> e;
            if(e != x){
                pos = true;
            }
            sum += e;
        }
        if(sum == x){
            cout << "NO" << endl;
            continue;
        }
        else{
            sort(arr.begin(), arr.end());
            ll sum = 0;
            for(int i = 0; i<n-1; i++){
                sum += arr[i];
                if(sum == x){
                    swap(arr[i], arr[i+1]);
                    sum -= arr[i+1];
                    sum += arr[i];
                }
            }
            if(sum == x){
                cout << "NO" << endl;
            }
            else{
                cout << "YES" << endl;
                for(auto& e : arr){
                    cout << e << " ";
                }
                cout << endl;
            }
        }

    }
    return 0;
}