#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

bool palinDrop(vector<int> &arr, int left, int right, int x){
    bool palin = true;
    while(left<right){
        if(arr[left] != arr[right]){
            if(arr[left] == x){
                left++;
            }
            else if(arr[right] == x){
                right--;
            }
            else{
                return false;
            }
        }
        else{
            left++;
            right--;
        }
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i<n; i++){
            cin >> arr[i];
        }
        bool klim = true;
        int i = 0, j = n-1;
        while(i<j){
            if(arr[i] != arr[j]){
                bool a1 = palinDrop(arr, i, j, arr[i]), a2 = palinDrop(arr, i, j, arr[j]);
                if(a1 || a2){
                    //cout << "YES" << endl;
                    klim = true;
                }
                else{
                    //cout << "NO" << endl;
                    klim = false;
                }
                break;
            }
            i++;
            j--;
        }
        cout << (klim?"YES":"NO") << endl;

    }
    return 0;
}