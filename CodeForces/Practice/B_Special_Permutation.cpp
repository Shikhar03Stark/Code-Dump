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
        int n, a, b;
        cin >> n >> a >> b;
        vector<int> ans(n);
        int x = 0, y = n/2;
        bool pos = true;
        vector<int> A, B, C, D;
        for(int i = 1; i<=n; i++){
            if(i == a || i == b) continue;
            if(i>a && i<b){
                C.push_back(i);
            }
            else if(i>=a){
                A.push_back(i);
            }
            else if(i <= b) {
                B.push_back(i);
            }
            else{
                D.push_back(i);
            }
        }
        if(A.size()>=n/2 || B.size()>=n/2){
            pos = false;
        }
        if(D.size()>0){
            pos = false;
        }
        if(pos){
            ans[n/2-1] = a;
            ans[n-1] = b;
            for(int i = 0; i<A.size(); i++){
                ans[i] = A[i];
            }
            for(int i = 0; i<B.size(); i++){
                ans[n/2+i] = B[i];
            }
            int idx = 0;
            for(int i = 0; i<n; i++){
                if(ans[i] == 0){
                    ans[i] = C[idx++];
                }
            }

            for(auto& e: ans){
                cout << e << " ";
            }
            cout << endl;
        }
        else{
            cout << -1 << endl;
        }

    }
    return 0;
}