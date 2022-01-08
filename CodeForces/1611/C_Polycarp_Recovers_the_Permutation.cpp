#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }   
    if(arr[0] == n || arr[n-1] == n){
        deque<int> Q;
        int mid = 0;
        for(int left = 0, right = n-1; left<=right; ){
            if(left==right){
                mid = arr[left];
                break;
            }
            if(arr[left] < arr[right]){
                Q.push_front(arr[left]);
                left++;
            }
            else{
                Q.push_back(arr[right]);
                right--;
            }
        }
        if(arr[0] == n){
            Q.push_back(mid);
        }
        else{
            Q.push_front(mid);
        }
        for(auto &p : Q){
            cout << p << " " ;
        }
        cout << endl;
    }
    else{
        cout << -1 << endl;
    }
    return 0;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}