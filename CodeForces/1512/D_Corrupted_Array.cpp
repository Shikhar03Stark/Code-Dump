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
        vector<int> b(n+2);
        for(auto& e : b){
            cin >> e;
        }
        sort(begin(b), end(b));
        ll sum = 0;
        bool possible = true;
        for(int i = 0; i<=n; i++){
            sum += b[i];
            if(sum <= 0){
                //overflow
                possible = false;
                break;
            }
        }

        if(!possible){
            cout << -1 << endl;
        }
        bool done = false;
        for(int i = 0; i<=n; i++){
            //leave i
            if(i == n){
                if(sum - b[n] == b[n+1] || sum - b[n] == b[n]){
                    for(int j = 0; j<=n; j++){
                    if(j!=i){
                        cout << b[j] << " ";
                        }
                    }
                    cout << endl;
                    done = true;
                    break;
                }
            }
            else if(sum - b[i] == b[n+1]){
                for(int j = 0; j<=n; j++){
                    if(j!=i){
                        cout << b[j] << " ";
                    }
                }
                cout << endl;
                done = true;
                break;
            }
        }

        if(!done){
            cout << -1 << endl;
        }
        
    }
    return 0;
}