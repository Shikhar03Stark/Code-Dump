#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int main(){
    int n, t;
    cin >> n >> t;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    int right = 0;
    int wind = 0;
    int sum = 0;
    for(int left = 0; left<n; left++){
        if(left){
            sum -= arr[left-1];
        }
        while(right<n && sum + arr[right] <= t){
            sum += arr[right++];
        }
        wind = max(wind, right-left);
    }
    cout << wind << endl;
    return 0;
}