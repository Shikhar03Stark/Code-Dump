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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int left=0, right=n-1;
        while(s[left] == '<'){
            left++;
        }
        while(s[right] == '>'){
            right--;
        }

        cout << min(left, n-1-right) << endl;

    }
    return 0;
}