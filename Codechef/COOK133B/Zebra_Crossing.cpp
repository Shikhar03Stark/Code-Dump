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
        string arr;
        cin >> arr;
        int r1 = n, r0 = n;
        for(int i = n-1; i>=0 && (r1 == n || r0 == n); i--){
            if(arr[i] == '0' && r0 == n){
                r0 = i;
            }
            if(arr[i] == '1' && r1 == n){
                r1 = i;
            }
        }
        int change = 0;
        for(int i = 1 ; i<n; i++){
            if(arr[i-1] != arr[i]){
                change++;
            }
        }
        if(k > change){
            cout << -1 << endl;
        }
        else{
            if(arr[0] == '1'){
                if(k%2 == 0){
                    cout << r1+1 << endl;
                }
                else{
                    cout << r0+1 << endl;
                }
            }
            else{
                if(k%2 == 0){
                    cout << r0+1 << endl;
                }
                else{
                    cout << r1+1 << endl;
                }
            }
        }

    }
    return 0;
}