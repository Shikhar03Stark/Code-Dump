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
        vector<int> A(n), B(n);
        for(auto& e : A){
            cin >> e;
        }
        for(auto& e : B){
            cin >> e;
        }

        sort(A.begin(), A.end());
        sort(B.begin(), B.end(), greater<int>());

        ll ma = 0;
        for(int i = 0; i<n; i++){
            if(ma < A[i]+B[i]){
                ma = A[i] + B[i];
            }
        }

        cout << ma << endl;
    }
    return 0;
}