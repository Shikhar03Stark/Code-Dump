// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void buildSeg(vector<int> &arr, vector<int> &seg, int node, int sl, int sr){
    if(sl == sr){
        seg[node] = arr[sl];
    }
    else{
        int mid = sl + (sr-sl)/2;
        buildSeg(arr, seg, 2*node, sl, mid);
        buildSeg(arr, seg, 2*node+1, mid+1, sr);

        //function
        seg[node] = seg[2*node] + seg[2*node+1];
    }
}

void updatePoint(vector<int> &arr, vector<int> &seg, int node, int sl, int sr, int idx, int val){
    if(sl==sr){
        seg[node] = val;
        arr[sl] = val;
    }
    else{
        int mid = sl + (sr-sl)/2;
        if(idx<=mid){
            updatePoint(arr, seg, 2*node, sl, mid, idx, val);
        }
        else{
            updatePoint(arr, seg, 2*node+1, mid+1, sr, idx, val);
        }

        //function
        seg[node] = seg[2*node] + seg[2*node+1];
    }
}

int queryRange(vector<int> &seg, int node, int sl, int sr, int left, int right){
    if(right < sl || left > sr ){
        //Identity
        return 0;
    }
    else if(left==sl && sr==right){
        return seg[node];
    }
    else{
        int mid = sl + (sr-sl)/2;
        int ql = queryRange(seg, 2*node, sl, mid, left, min(mid, right));
        int qr = queryRange(seg, 2*node+1, mid+1, sr, max(mid+1, left), right);

        //function
        return ql+qr;
    }
}

void solve(){
    auto ms = chrono::system_clock::to_time_t( chrono::system_clock::now() );
    srand((ull)ms);
    const int N = 1000;
    int n = rand()%N + 1;
    vector<int> arr(n);
    for(auto& e: arr){
        e =  2*(rand()%N + 1);
    }
    cout << "Array of size " << n << " init." << nl;
    vector<int> seg(4*n, 0);
    buildSeg(arr, seg, 1, 0, n-1);
    int ops = rand()%1000 + 1;
    cout << "Number of Ops " << ops << nl;
    for(int x = 0; x<ops; x++){
        int type = rand()%2;
        if(type){
            //range sum [l,r]
            int r = rand()%n;
            int l = rand()%r;
            int lin_sum = 0;
            for(int i = l; i<=r; i++){
                lin_sum += arr[i];
            }
            int seg_sum = queryRange(seg, 1, 0, n-1, l, r);
            if(seg_sum != lin_sum){
                cerr << "Miss-Match" << nl;
                // for(auto& e: arr){
                //     cout << e << " ";
                // }
                cout << l << " to " << r << nl;
                for(int i = 0; i<n; i++){
                    if(i==l || i==r){
                        cout << '[' << arr[i] << "] ";
                    }
                    else{
                        cout << arr[i] << " ";
                    }
                }
                cout << nl;
                exit(1);
            }
            else{
                cout << l << " to " << r << " correct " << seg_sum << nl;
            }
        }
        else{
            //update at p
            int p = rand()%N;
            int val = N - 2*(rand()%N+1);
            updatePoint(arr, seg, 1, 0, n-1, p, val);
            cout << "Updated " << p << " with " << val << nl;
        }
    }

    return;
}

int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}