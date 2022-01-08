#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

bool solve(vector<int>& blue, vector<int>& red, int n){
    sort(blue.begin(), blue.end());
    sort(red.begin(), red.end());
    //set blue 1..blue.size()
    int pos = 1;
    for(int i = 0; i<blue.size();i++){
        if(blue[i] < pos){
            return false;
        }
        pos++;
    }
    for(int i = 0; i<red.size(); i++){
        if(red[i] > pos){
            return false;
        }
        pos++;
    }
    return true;
}

int main(){
    FASTIO
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(auto&e:arr){
            cin >> e;
        }
        string type;
        cin >> type;
        vector<int> blues, reds;
        for(int i = 0; i<n; i++){
            if(type[i] == 'B'){
                blues.push_back(arr[i]);
            }
            else{
                reds.push_back(arr[i]);
            }
        }

        bool ans = solve(blues, reds, n);
        cout << (ans?"YES":"NO") << endl;

    }
    return 0;
}