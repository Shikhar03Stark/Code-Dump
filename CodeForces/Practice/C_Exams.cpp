#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> arr(n);
    for(int i = 0; i<n; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end());
    int prev = 0;
    for(int i = 0 ; i<n; i++){
        if(arr[i].second >= prev){
            prev = arr[i].second;
        }
        else if(arr[i].first >= prev){
            prev = arr[i].first;
        }
    }
    cout << prev << endl;
    return 0;
}