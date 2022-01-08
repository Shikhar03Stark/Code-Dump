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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        
        bool offen = false;
        int count = 0;
        for(int i = 0; i<n; i++){
            if(i){
                if(s[i] == '*' && s[i-1] == '*'){
                    count++;
                }
                else if(s[i] == '*'){
                    count = 1;
                }
                else{
                    count = 0;
                }
            }
            else{
                if(s[0] == '*'){
                    count++;
                }
            }
            
            if(count >= k){
                    offen = true;
                    break;
            }
        }

        if(offen){
            cout << "YES" << endl;
        }
        else{
            cout << "NO"  << endl;
        }
    }
    return 0;
}