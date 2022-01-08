
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

string sub[] = {"01","12", "23", "34", "45", "56", "67", "78", "89", "90"};
map<string,char> h;

bool exists(string &s){
    int n = s.size();
    for(int i = 1; i<n; i++){
        if(s[i]-s[i-1]==1)
            return true;
        if(s[i]=='0' && s[i-1]=='9')
            return true;
    }

    return false;
}
int main(){
    for(int i = 0; i<10; i++){
        h[sub[i]] = '0'+(i+2)%10;
    }
    int ttt;
    cin>>ttt;
    for(int z = 1; z<=ttt; z++){
        cout << "Case #" << z << ": ";
        int n;
        cin >> n;
        string s;
        cin >> s;
        string t = s;
        while(exists(t)){
            for(int o = 0; o<10; o++){
                for(int k = t.size()-2; k>=0; k--){
                    string part = t.substr(k,2);
                    if(k<t.size()-1 && (part==sub[o])){
                        //match further
                        char c = t[k+1];
                        int left = k-1;
                        bool match = false;
                        while(k>=0 && t[left]==c){
                            match = true;
                            left--;
                            c -= '0';
                            c = (c+1)%10;
                            c += '0';
                        }
                        if(!match){
                            t.erase(t.begin()+k, t.begin()+k+2);
                            t.insert(t.begin()+k, h[part]);
                            k--;
                        }
                        else{
                            left++;
                            c -= '0';
                            c = (10+c-1)%10;
                            t.erase(t.begin()+left, t.begin()+k+2);
                            t.insert(t.begin()+left, h[sub[c]]);
                            k = left;
                        }
                    }
                }
            }
        }
        cout << t << endl;
    }
    return 0;
}

