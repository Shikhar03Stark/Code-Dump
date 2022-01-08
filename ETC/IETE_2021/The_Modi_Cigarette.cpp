#include <bits/stdc++.h>
#define show(x) cerr << #x << '=' << x << endl;
#define FOR(i, s, n) for(int i=0; i<(int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
using namespace std;

typedef pair<int,int> PII;
typedef unsigned long long ull;
typedef pair<ull,ull> PUU;

const int MAX = 3 * 10000 + 10;
const int P1 = 1000003;
const int P2 = 5000011;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(auto& e : arr){
        cin >> e;
    }
    sort(arr.begin(), arr.end());
    int ans = 0;
    int start = 0; 
    int end = k-1;
    int min = INT_MAX;
    int l, r;
    while(end < n){
        if(min > arr[end] - arr[start]){
            min = arr[end] - arr[start];
            l = start;
            r = end;
        }
        start++;
        end++;
    }

    for(int i = l; i<=r; i++){
        ans += arr[i];
    }

    cout << ans << endl;


    return 0;
}