#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n, w;
        cin >> n >> w;
        multiset<int> s;
        for(int i = 0; i<n; i++){
            int data;
            cin >> data;
            s.insert(data);
        }
        int height = 1;
        int rem = w;
        while(!s.empty()){
            auto itr = s.upper_bound(rem);
            if(itr != s.begin()){
                --itr;
                rem -= (*itr);
                s.erase(itr);
            }
            else{
                rem = w;
                ++height;
            }
        }

        cout << height << endl;
    }
    return 0;
}