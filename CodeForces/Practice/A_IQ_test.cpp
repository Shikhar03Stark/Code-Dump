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
    for(auto&e:arr){
        cin >> e;
    }
    int ei=0,oi=0, ec=0, oc=0;
    for(int i = 0; i<n; i++){
        if(arr[i]%2==0){
            ei=i;
            ec++;
        }
        else{
            oi=i;
            oc++;
        }
    }
    if(oc>ec){
        cout << ei+1 << endl;
    }
    else{
        cout << oi+1 << endl;
    }
    return 0;
}