#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int mindiv(int num){
    if(num%2 == 0) return 2;
    for(int i = 3; i*i<=num; i += 2){
        if(num%i == 0) return i;
    }
    return num;
}

int main(){
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    vector<pair<int,int>> que(q);
    for(int i = 0; i<q; i++){
        cin >> que[i].first >> que[i].second;
    }
    vector<int> divs(n);
    for(int i = 0; i<n; i++){
        divs[i] = mindiv(arr[i]);
    }
    vector<int> prefix(n+1, 0);
    for(int i = 0; i<n; i++){
        prefix[i+1] = prefix[i] + divs[i];
    }

    for(auto& q: que){
        int l = q.first, r = q.second;
        cout << prefix[r] - prefix[l-1] << endl;
    }

    return 0;
}