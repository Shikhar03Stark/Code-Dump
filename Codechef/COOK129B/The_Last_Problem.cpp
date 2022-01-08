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
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int Y = max(y1, y2), X = max(x1, x2);
        int sum = 0;
        int val = 1;
        int x = 1, y = 1;
        for(int i = 1; i<x1; i++){
            val += val + (i);
        }
        for(int i = 1; i<y1; i++){
            val += val + (i + x1 - 1);
        }
        ull sum = val;
        
    
    }
    return 0;
}