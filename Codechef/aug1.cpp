#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define long long int ll;

using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int *arr = new int[n];
        for(int i=0; i<n;i++){
            cin >> arr[i];
        }

        int distance = 0;
        bool isFound = false;
        bool following = true;
        for(int i =0 ; i<n; i++){
            if(!isFound){
                if(arr[i] == 1){
                    isFound = true;
                    distance = 0;
                }
            }
            else{
                distance++;
                if(arr[i] == 1){
                    if(distance >= 6){
                        distance=0;
                    }
                    else{
                        following = false;
                        break;
                    }
                }
            }
        }
        if(following)
        cout << "YES" << endl;
        else
        cout << "NO" << endl;
    }
    return 0;
}