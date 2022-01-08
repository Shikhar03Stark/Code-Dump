#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

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

        set<int> s;
        vector<int> left;
        for(int i = 0; i<n; i++){
            if(s.find(arr[i]) == s.end()){
                s.insert(arr[i]);
            }
            else{
                left.push_back(arr[i]);
            }
        }
        sort(left.begin(), left.end());
        for(auto& e: s){
            cout << e << " ";
        }
        for(int i = 0; i<left.size(); i++){
            cout << left[i] << " ";
        }
        cout << endl;
    }
    return 0;
}