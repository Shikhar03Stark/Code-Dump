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
        int n, p, x, y;
        cin >> n >> p >> x >> y;
        vector<int> arr(n);
        for(int i = 0; i<n; i++){
            cin >> arr[i];
        }
        p--;
        int nx = 0, ny = 0;
        for(int i = 0; i<p; i++){
            if(arr[i]==1) ny++;
            if(arr[i]==0) nx++;
        }
        cout << y + nx*x + ny*y << endl;
    }
    return 0;
}