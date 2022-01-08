#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int z = 1; z<=t; z++){
        cout << "Case #" << z << ": ";
        int n, s;
        cin >> n >> s;
        string str;
        cin >> str;
        int good = 0;
        for(int i = 0; i<n/2; i++){
            char c = str[n-i-1];
            if(str[i] != c){
                good++;
            }
        }

        cout << abs(s-good) << endl;
    }
    return 0;
}