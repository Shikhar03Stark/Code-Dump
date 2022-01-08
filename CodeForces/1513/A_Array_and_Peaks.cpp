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
        if(k > (n-1)/2){
            cout << -1 << endl;
        }
        else{
            vector<int> arr(n,1);
            for(int i = 1; i<n; i++){
                arr[i] = arr[i-1] + arr[i];
            }

            int left = 0, right = n-1;
            while(k){
                if(left == right){
                    cout << arr[left] << " ";
                }
                else{
                    cout << arr[left] << " " << arr[right] << " ";
                }
                k--;
                left++;
                right--;
            }

            if(left <= right){
                for(int i = left; i<=right; i++){
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
            else{
                cout << endl;
            }
        }
    }
    return 0;
}