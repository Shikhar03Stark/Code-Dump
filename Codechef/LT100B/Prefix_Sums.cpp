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
        if(n>0 && n%4 == 0){
            vector<int> arr1, arr2;
            for(int i = 1; i<=n/2; i+=2){
                arr1.push_back(i);
                arr1.push_back(n+1-i);
            }
            for(int i = 2; i<=n/2; i+=2){
                arr2.push_back(i);
                arr2.push_back(n+1-i);
            }
            sort(arr2.begin(), arr2.end());
            sort(arr1.begin(), arr1.end());
            cout << "YES" << endl;
            for(auto&e: arr1){
                cout << e << " ";
            }
            cout << endl;
            for(auto& e: arr2){
                cout << e << " ";
            }
            cout << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}