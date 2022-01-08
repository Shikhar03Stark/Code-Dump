#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        string s;
        cin >> n >> k;
        cin >> s;

        int i = 0, j = n-1;
        bool invalid = false;
        while(k>0 && i<=j){
            if(s[i] != s[j]){
                invalid = true;
                break;
            }
            k--;
            ++i;
            --j;
        }

        if(j-i+1 <= 0 || invalid){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }
    return 0;
}