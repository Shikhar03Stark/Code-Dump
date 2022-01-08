#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    int n, k;
    cin >> n >> k;
    vector<short> digits;
    while(n){
        digits.push_back(n%10);
        n /= 10;
    }
    if(digits.size() == 0){
        digits.push_back(0);
    }
    int sz = digits.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i<sz; i++){
        pq.push(digits[i]);
    }
    ll ans = 1;
    while(k){
        //int low = false;
        ll top = pq.top(); pq.pop();
        if(top==9){
            pq.push(9);
            break;
        }
        else{
            top++;
            pq.push(top);
        }
        k--;
    }
    while(!pq.empty()){
        int top = pq.top(); pq.pop();
        ans *= top;
        cerr << top << " ";
    }
    cerr << endl;

    cout << ans << endl;

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