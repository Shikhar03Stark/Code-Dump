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
        k++;
        vector<ull> arr(n);
        for(int i = 0; i<n; i++){
            int data;
            cin >> data;
            arr[i] = pow(10,data);
        }
        vector<ull> maxi(n);
        for(int i = 0; i<n-1; i++){
            maxi[i] = arr[i+1]/arr[i]*arr[i] - arr[i];
        }
        ull total = 0;
        int idx = 0;
        while(k>0){
            if(idx<n-1){
                int cnt = maxi[idx]/arr[idx];
                if(cnt > k){
                    total += k*arr[idx];
                    k = 0;
                }
                else{
                    total += cnt*arr[idx];
                    k -= cnt;
                }
                idx++;
            }
            else{
                total += k*arr[idx];
                k = 0;
            }
        }

        cout << total << endl;
    }
    return 0;
}