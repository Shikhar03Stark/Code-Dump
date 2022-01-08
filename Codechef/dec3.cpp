#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, d;
        cin >> n >> d;
        vector<int> risk;
        vector<int> normal;
        for(int i = 0; i<n;i++){
            int age;
            cin >> age;
            if(age <= 9 || age >= 80){
                risk.push_back(age);
            }
            else{
                normal.push_back(age);
            }
        }
        int days = 0;
        //first exhaust risky array
        if(risk.size()%d == 0){
            days += risk.size()/d;
        }else{
            days += risk.size()/d + 1;
        }

        //normal patients
        if(normal.size()%d == 0){
            days += normal.size()/d;
        }
        else{
            days += normal.size()/d + 1;
        }

        cout << days << endl;

    }
    return 0;
}