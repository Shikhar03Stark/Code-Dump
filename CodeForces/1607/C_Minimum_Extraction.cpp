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
        for(auto&e:arr){
            cin >> e;
        }
        sort(arr.begin(), arr.end());
        vector<int> pre(n,0), res(n,0);
        pre[0] = 0;
        res[0] = arr[0];
        for(int i = 1; i<n; i++){
            pre[i] = pre[i-1]-res[i-1];
            res[i] = arr[i]+pre[i];
        }
        /*for(auto&e:pre){
            cerr << e << " ";
        }
        cerr << endl;
        for(auto&e:arr){
            cerr << e << " ";
        }
        cerr << endl;
        for(auto&e:res){
            cerr << e << " ";
        }
        cerr << endl << endl;*/
        cout << *max_element(res.begin(), res.end()) << endl;
    }
    return 0;
}