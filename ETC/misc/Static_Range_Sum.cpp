#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    vector<ull> prefix(n,0);
    for(int i = 0; i<n; i++){
        if(i){
            cin >> prefix[i];
            prefix[i] += prefix[i-1];
        }
        else{
            cin >> prefix[i];
        }
    }

    for(int i = 0 ;i<q; i++){
        int start, end;
        cin >> start >> end;
        end--;
        if(start==0){
            cout << prefix[end] << endl;
        }
        else{
            cout << prefix[end] - prefix[start-1] << endl;
        }
    }

    return 0;
}