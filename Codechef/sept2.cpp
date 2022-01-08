#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int val = 1;
        vector<bool> arr(n);
        ll data;
        for(int i = 0; i<arr.size(); i++){
            cin >> data;
            if(data == val){
                arr[i] = true;
            }
            else{
                arr[i] = false;
            }
            ++val;
        }

        for(int i = 0; i<(n*n - n); i++){
            cin >> data;
        }

        int swit = 0;
        for(int i = 2; i<arr.size(); i++){
            if(arr[i-1] != arr[i]){
                swit++;
            }
        }

        if(arr[arr.size() - 1] == false){
            ++swit;
        }

        cout << swit << endl;
    }
    return 0;
}