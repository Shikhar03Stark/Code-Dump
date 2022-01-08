#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    string s;
    for(int i = 0; i<n; i++){
        s.push_back('*');
    }
    int rem = 0;
    int left = 0, right = n-1;
    while(left<=right){
        s[left] = rem + 'a';
        s[right] = rem + 'a';
        left++;
        right--;
        rem = (rem+1)%k;
    }

    cout << s << endl;
    return 0;
}