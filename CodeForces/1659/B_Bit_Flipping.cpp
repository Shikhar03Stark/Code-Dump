// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void pre(){
    
    return;
}

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int> f(n,0);
    int tmpk=k;
    for(int i=0;i<n && tmpk>0;i++)
    {
        if(k%2==s[i]-'0')
        {
            f[i]=1;
            tmpk--;
        }
    }
    f[n-1]+=tmpk;
    for(int i=0;i<n;i++)
    {
        if((k-f[i])%2==1)   s[i]='1'-(s[i]-'0');
    }
    cout<<s<<endl;
    for(auto& e:f)  cout<<e<<" ";
    cout<<endl;
    // int n, k;
    // cin >> n >> k;
    // string s;
    // cin >> s;
    // int t=k;
    // vector<int> f(n, 0);
    // for(int i = 0; i<n && t>0; i++){
    //     if(t%2 == 1){
    //         if(s[i] == '1'){
    //             f[i] = 1;
    //             t--;
    //         }
    //     }
    //     else if(t%2 == 0){
    //         if(s[i] == '0'){
    //             f[i] = 1;
    //             t--;
    //         }
    //     }
    // }
    // f[n-1] += t;
    // for(int i = 0; i<n; i++){
    //     if((k-f[i])%2 == 0){
    //         cout << s[i];
    //     }
    //     else{
    //         cout << (!(s[i]-'0'));
    //     }
    // }
    // cout << nl;
    // for(int i = 0; i<n; i++){
    //     cout << f[i] << " ";
    // }
    // cout << nl;
    return;
}

int main(){
    FASTIO
    pre();
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}