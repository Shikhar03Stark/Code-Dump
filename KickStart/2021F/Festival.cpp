#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

struct Range{
    int happy;
    int st, end;
};

int main(){
    int t;
    cin>>t;
    for(int z = 1; z<=t; z++){
        cout << "Case #" << z << ": ";
        int d, n, k;
        cin >> d >> n >> k;
        vector<Range> arr(n);
        for(int i = 0; i<n; i++){
            cin >> arr[i].happy >> arr[i].st >> arr[i].end;
        }

        auto comp = [](const Range &a, const Range &b)->bool{
            return (a.end == b.end)?a.st <= b.st:a.end<b.end;
        };
        sort(arr.begin(), arr.end(), comp);
        unordered_map<int, bool> vis;
        ll maxi = 0;
        int prev = -1;
        for(int i = 0; i<n; i++){
            int end = arr[i].end;
            if(vis[end] == true) continue;
            vis[end] = true;
            vector<int> happ;
            happ.push_back(arr[i].happy);
            for(int j = i+1; j<n; j++){
                if(arr[j].st <= end && end <= arr[j].end){
                    happ.push_back(arr[j].happy);
                }
            }
            sort(happ.begin(), happ.end(), greater<int>());
            ll sum = 0;
            for(int j = 0; j<k && j<happ.size(); j++){
                sum += happ[j];
            }

            maxi = max(maxi, sum);
        }

        cout << maxi << endl;
    }
    return 0;
}