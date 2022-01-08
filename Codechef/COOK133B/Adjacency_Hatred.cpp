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
        for(int i = 0; i<n; i++){
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        int sum = 0;
        for(int i = 1; i<n; i++){
            sum += abs(arr[i] - arr[i-1]);
        }
        deque<int> Q;
        for(int i = 0; i<n; i++){
            Q.push_back(arr[i]);
        }
        int rota = 0;
        while(sum%2 == 0 && rota < n){
            int back = Q.back(); Q.pop_back();
            sum -= abs(back - Q.back());
            sum += abs(back - Q.front());
            Q.push_front(back);
            rota++;
        }

        if(sum%2 == 0){
            cout << -1 << endl;
        }
        else{
            while(!Q.empty()){
                int e = Q.front(); Q.pop_front();
                cout << e << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}