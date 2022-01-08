#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int main(){
    ll m, s;
    cin >> m >> s;
    if(m == 1 && s>=0 && s<=9){
        for(int i = 0; i<m; i++){
            cout << s;
        }
        cout << " ";
        for(int i = 0; i<m; i++){
            cout << s;
        }
    }
    else if(s>= 1 && s <= 9*m){
        vector<int> lar(m, 0), sml(m, 0);
        int sum = s;
        for(int i = 0; i<m && sum>0; i++){
            if(sum > 9){
                lar[i] = 9;
                sum -= 9;
            }
            else{
                lar[i] = sum;
                sum = 0;
            }
        }
        sum = s-1;
        sml[0] = 1;
        for(int i = m-1; i>=0 && sum>0; i--){
            if(sum > 9){
                sml[i] += 9;
                sum -= 9;
            }
            else{
                sml[i] += sum;
                sum = 0;
            }
        }
        //if()
        for(auto& e: sml){
            cout << e;
        }
        cout << " ";
        for(auto& e: lar){
            cout << e;
        }


    }
    else{
        cout << -1 << " " << -1 << endl;
    }
    return 0;
}