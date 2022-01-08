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
        vector<ll> arr(n);
        for(int i = 0; i<n; i++){
            cin >> arr[i];
        }
        sort(arr.rbegin(), arr.rend());
        double sum = 0;
        vector<double> pre(n);
        for(int i = n-1; i>=0; i--){
            sum += arr[i];
            double mean = sum/(n-i);
            int terms = (n-i);
            double median;
            if(terms%2==0){
                median = (arr[i+(n-i)/2] + arr[i-1+(n-i)/2])/2.0;
            }
            else{
                median = arr[i+(n-i)/2];
            }
            pre[n-i-1] = mean - median;
        }
        for(int i = 0; i<n; i++){
            cerr << pre[i] << " ";
        }
        cerr << endl;
        int idx = n;
        for(int i = 0; i<n; i++){
            if(pre[i] < 0.0){
                idx = i;
                break;
            }
        }
        bool haspos = false;
        for(int i = 0; i<n; i++){
            if(pre[i] > 0.0){
                haspos = true;
                break;
            }
        }
        cout << (haspos?(n-idx):0) << endl;
    }
    return 0;
}