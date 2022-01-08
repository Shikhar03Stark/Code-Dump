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
        vector<int> a(n), b(n);
        for(auto& e: a){
            cin >> e;
        }
        for(auto& e: b){
            cin >> e;
        }

        for(int i = 0; i<n-2; i++){
            if(a[i] > b[i]) break;
            int ops = b[i] - a[i];
            a[i] += ops;
            a[i+1] += ops*2;
            a[i+2] += ops*3;
        }

        bool match = true;
        for(int i = 0; i<n; i++){
            if(a[i] != b[i]){
                match = false;
                break;
            }
        }
        cout << (match?"TAK":"NIE") << endl;
    }
    return 0;
}