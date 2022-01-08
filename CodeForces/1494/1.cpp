#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

bool isBalanced(string& s){
    stack<char> st;
    for(auto& c: s){
        if(c == ')'){
            if(st.empty()){
                return false;
            }
            st.pop();
        }
        else{
            st.push('(');
        }
    }

    if(!st.empty()){
        return false;
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin >> s;
        bool found  = false;
        for(int i = 1;i<7; i++){
            bitset<3> b = i;
            string seq(s.size(), 'a');
            for(int i = 0; i<seq.size(); i++){
                if(s[i] == 'A'){
                    seq[i] = (b[0] == 1)? '(' : ')';
                }
                if(s[i] == 'B'){
                    seq[i] = (b[1] == 1)? '(' : ')';
                }
                if(s[i] == 'C'){
                    seq[i] = (b[2] == 1)? '(' : ')';
                }
            }

            if(isBalanced(seq)){
                found = true;
                break;
            }
        }

        if(found){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}