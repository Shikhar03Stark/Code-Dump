#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;

        bool inSnake = false;

        for(int i = 0; i<n; i++){
            if (!(s[i] == '.')) {
                if(s[i] == 'H'){
                    if(inSnake == true){
                        break;
                    }
                    inSnake = true;
                }
                if(s[i] == 'T'){
                    if(inSnake == false){
                        inSnake = true;
                        break;
                    }
                    inSnake = false;
                }
            }
        }

        if(!inSnake){
            cout << "Valid" << endl;
        }
        else{
            cout << "Invalid" << endl;
        }
    }
    return 0;
}