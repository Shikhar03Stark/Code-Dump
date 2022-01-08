#include <bits/stdc++.h>
using namespace std;

typedef unsigned long int ui;
typedef long int i;

int main(){
    int t ;
    cin >> t;
    while(t--){
        i x, y ,k, n;
        cin >> x >> y >> k >> n;
        ui size = x - y;
        vector<pair<ui, ui> > book(n);
        vector<float> eff(n);
        for(int i = 0; i<n; i++){
            cin >> book[i].first >> book[i].second;
            eff[i] = (book[i].first+0.0)/book[i].second;
        }



        sort(book.begin(), book.end(), [](pair<ui,ui> l, pair<ui,ui> r){
            return (l.second <= r.second);
        });

        //for(int i=0;i<)



    }
    return 0;
}