#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    ll prev = 0;
    ll cnt = 0;
    for(int i = 0; i<n; i++){
        if(arr[i]>=prev){
            cnt++;
            prev += arr[i];
        }
    }
    cout << cnt << endl;

    return 0;
}