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
        vector<int> left(n, INT_MAX), right(n, INT_MAX);
        for(int i = 0; i<n; i++){
            if(s[i] == '1'){
                left[i] = 0;
            }
            else{
                if(i-1 >= 0 && left[i-1] < INT_MAX){
                    left[i] = left[i-1] + 1;
                }
            }
        }

        for(int i = n-1; i>= 0; i--){
            if(s[i] == '1'){
                right[i] = 0;
            }
            else{
                if(i+1 < n && right[i+1] < INT_MAX){
                    right[i] = right[i+1] + 1;
                }
            }
        }

        for(auto& e: left){
            cerr << e << " ";
        }
        cerr << endl;
        for(auto& e: right){
            cerr << e << " ";
        }
        cerr << endl;
        cerr << endl;

        ll sum = 0;
        for(int i = 0; i<n; i++){
            sum += min(left[i], right[i]);
        }
        cout << sum << endl;
    }
    return 0;
}