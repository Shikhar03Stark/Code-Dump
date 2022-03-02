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

void showAll(vector<int> arr, map<int,int> &idx, vector<int> &half){
    int n = arr.size();
    cerr << "ARR: ";
    for(int i = 1; i<n; i++){
        cerr << arr[i] << " ";
    }
    cerr << nl;
    cerr << "IDX: ";
    for(int i = 1; i<n; i++){
        cerr << idx[arr[i]] << " ";
    }
    cerr << nl;
    cerr << "HAF: ";
    for(int i = 1; i<n; i++){
        cerr << half[arr[i]] << " ";
    }
    cerr << nl;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> v(n+m+1);
    for(int i=1;i<=n+m;i++)
        cin>>v[i];
    vector<int> p;
    p=v;
    sort(p.begin(),p.end());
    int ans=0;
    for(int i=1;i<=n+m;i++){
        if(v[i]==p[i])
            continue;
        if(i<=n){
            int x=v[v[i]];
            if(v[i]>n){
                swap(v[i],v[v[i]]);
                ans++;
            }
            else{
                if(x<=n){
                    ans+=3;
                    swap(v[i],v[v[i]]);
                }
                else{
                    swap(v[i],v[x]);
                    swap(v[v[i]],v[x]);
                    ans+=2;
                }
            }
        }
        else{
            int x=v[v[i]];
            swap(v[i],v[v[i]]);
            ans+=3;
        }
    }
    cout<<ans<<endl;
    return;
}

int main(){
    FASTIO
    pre();
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}