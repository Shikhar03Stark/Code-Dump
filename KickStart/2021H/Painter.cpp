#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int R = 4, Y = 2, B = 1, O=6, P=5, G=3, A=7;


int main(){
    int t;
    cin>>t;
    for(int z = 1; z<=t; z++){
        cout << "Case #" << z << ": ";
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> col(n);
        for(int i = 0; i<n; i++){
            if(s[i]=='R')
                col[i]=R;
            if(s[i]=='Y')
                col[i]=Y;
            if(s[i]=='B')
                col[i]=B;
            if(s[i]=='O')
                col[i]=O;
            if(s[i]=='P')
                col[i]=P;
            if(s[i]=='G')
                col[i]=G;
            if(s[i]=='A')
                col[i]=A;
        }
        //int n = s.size();
        ll stroke = 0;
        for(int p = 0; (1<<p)<=4; p++){
            int i = (1<<p);
            int left = 0, right = 0;
            //cerr << i << endl;
            for(;left<n;left++){
                if( (col[left]&i) == i){
                    stroke++;
                    //cerr << "[" << left << " ";
                    while(left<n && (col[left]&i)==i){
                        left++;
                    }
                    //cerr << left << "]" << endl;
                }
            }
        }

        cout << stroke << endl;
    }
    return 0;
}