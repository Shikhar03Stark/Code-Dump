#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int z = 1; z<=t; z++){
        cout << "Case #" << z << ": ";
        int n;
        string s;
        cin >> n;
        cin >> s;
        int swt = 0;
        char prev = 0;
        for(int i = 0; i<n; i++){
            char c = s[i];
            if(c == 'X' || c == 'O'){
                if(prev == 0){
                    prev = c;
                }
                else{
                    if(prev != c){
                        swt++;
                    }
                    prev = c;
                }
            }
        }
        cout << swt << endl;
    }
    return 0;
}