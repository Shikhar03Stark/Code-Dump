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
        for(auto& e: arr){
            cin >> e;
        }
        if(n%2 == 0){
            cout << "no" << endl;
            continue;
        }
        int left = 0, right = n-1;
        if(arr[left] != 1 || arr[right] != 1){
            cout << "no" << endl;
        }
        else{
            bool good = true;
            while(left<=right){
                if(left == 0 && right == n-1);
                else{
                    if(arr[left] == arr[right] && arr[left] - arr[left-1] == 1);
                    else{
                        good = false;
                        break;
                    }
                }
                left++;
                right--;
            }

            if(good){
                cout << "yes" << endl;
            }
            else{
                cout << "no" << endl;
            }
        }
    }
    return 0;
}