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
        for(auto& e : arr){
            cin >> e;
        }

        int maximum = *(max_element(arr.begin(), arr.end()));
        set<int> S;
        bool possible = true;
        bool same = true;
        for(int i = 1; i<n; i++){
            if(arr[i] != arr[i-1]){
                same = false;
            }
            int lbefore = S.size();
            S.insert(abs(arr[i] - arr[i-1]));
            if(lbefore == 2 && S.size()>2){
                possible = false;
                break;
            }
        }

        if(!possible){
            cout << -1 << endl;
        }
        else{
            if(same){
                cout << 0 << endl;
            }
            else{
                int sum;
                if(S.size() == 1){
                    sum = 2* (*S.begin());
                }
                else{
                    sum = *S.begin() + *(++S.begin());
                }
                if(sum > maximum){
                    cout << sum << " " << *S.begin() << endl;
                }
                else{
                    cout << -1 << endl;
                }
            }
        }
    }
    return 0;
}