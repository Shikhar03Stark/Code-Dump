#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int height, energy = 0;
        cin >> height;
        while(height > 0){
            int jump = log(height)/log(4);
            height = height - pow(4, jump);
            energy += 101;
        }
        cout << energy << endl;
    }
    return 0;
}