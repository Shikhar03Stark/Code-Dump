#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

bool exists(string &s, int wind){
    int a = 0, b = 0, c=0;
    if(wind<3) return false;
    for(int i = 0; i<wind; i++){
        if(s[i]=='1') a++;
        if(s[i]=='2') b++;
        if(s[i]=='3') c++;
        if(a>0 && b>0 && c>0) return true;
    }
    int n = s.size();
    for(int i=wind; i<n; i++){
        if(s[i]=='1') a++;
        if(s[i]=='2') b++;
        if(s[i]=='3') c++;

        if(s[i-wind]=='1') a--;
        if(s[i-wind]=='2') b--;
        if(s[i-wind]=='3') c--;
        if(a>0 && b>0 && c>0) return true;
    }
    return false;

}

int solve(){
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    int left = 2, right=n;
    bool pos = false;
    while(left<=right){
        int mid = left+(right-left)/2;
        if(exists(s, mid)){
            //ans = (ans==0)?mid:min(mid, ans);
            pos = true;
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }
    if(pos){
        cout << left << endl;
    }
    else{
        cout << 0 << endl;
    }

    return 0;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}