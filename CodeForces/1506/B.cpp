#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int first = 0, last = n-1;
        for(;first<n;first++){
            if(s[first] == '*')
            break;
        }

        for(;last>=0; last--){
            if(s[last] == '*')
            break;
        }

        if(first==last){
            cout << 1 << endl;
        }
        else{
            int start = first;
            int end = start+k;
            int cnt = 2;
            while(end < last){
                for(int i = end; i>start; i--){
                    if(s[i] == '*'){
                        cnt++;
                        start = i;
                        end = start+k;
                        break;
                    }
                }
            }

            cout << cnt << endl;
        }
    }
    return 0;
}