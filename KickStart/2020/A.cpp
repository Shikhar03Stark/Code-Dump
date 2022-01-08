#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int z = 1; z<=t; z++){
        cout << "Case #" << z << " ";
        int n, p;
        cin >> n >> p;
        vector<int> price(n);
        for(auto& e: price){
            cin >> e;
        }

        sort(price.begin(), price.end());
        int count = 0;
        int h = 0;
        while(p>0 && h<n){
            p -= price[h];
            ++h;
            if(p>=0)
                ++count;
        }

        cout << count << endl;
    }
    return 0;
}