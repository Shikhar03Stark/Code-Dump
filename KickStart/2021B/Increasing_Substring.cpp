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
        cin >> n;
        string s;
        cin >> s;
        int order = 1;
        for(int i = 0; i<n; i++){
            if(i){
                if(s[i] > s[i-1]){
                    order++;
                }
                else{
                    order = 1;
                }
                cout << order << " ";
            }
            else{
                cout << order << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}