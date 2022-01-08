#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        if(n <= 3){
            cout << "YES" << endl;
            continue;
        }
        bool possible = true;
        for(int i = 0; i<n-1; i++){
            if(s[i] > s[i+1]){
                int ones = 0, zeros = 0;
                for(int j = i; j>=0;j--){
                    if(s[j] != '1')
                        break;
                    ones++;
                }
                for(int j = i+1; j<n ;j++){
                    if(s[j] != '0')
                        break;
                    zeros++;
                }
                if(ones >1 && zeros > 1){
                    //cout << "NO" << endl;
                    possible = false;
                }
            }
        }

        if(possible)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}