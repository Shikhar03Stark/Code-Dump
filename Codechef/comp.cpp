#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        int len = 0;
        stack<char> s;
        int i = 0;
        vector<int> arr;
        //bool streak = true;
        while(i<str.size()){
            if(s.empty()){
                arr.push_back(len);
            }
            if(str[i] == '<'){
                s.push(str[i]);
                ++len;
                ++i;
                continue;
            }

            if(str[i] == '>'){
                if(s.empty()){
                    break;
                }
                if(s.top() == '>'){
                    break;
                }
                s.pop();
                ++len;
                ++i;
                continue;
            }
        }
        if(!s.empty()){
            len = arr[arr.size()-1];
        }

        cout << len << endl;
    }
    return 0;
}