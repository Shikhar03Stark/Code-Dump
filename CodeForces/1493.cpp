#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

char mirror(char n){
    if(n == '3' || n == '4' || n == '6' || n == '7' || n == '9'){
        return '-';
    }
    else if(n == '0'){
        return '0';
    }
    else if(n == '1'){
        return '1';
    }
    else if(n == '2'){
        return '5';
    }
    else if(n == '5'){
        return '2';
    }
    else if(n == '8'){
        return '8';
    }
    return '-';
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int h, m;
        cin >> h >> m;
        string time;
        cin >> time;
        string hh = time.substr(0,2);
        string mm = time.substr(3);
        bool invalid = false;
        string mh = "", mmm = "";
        for(auto& c: hh){
            char mi = mirror(c);
            if(mi != '-'){
                mh.push_back(c);
            }
            else{
                invalid = true;
                break;
            }
        }
        for(auto& c : mm){
            char mi = mirror(c);
            if(mi != '-'){
                mmm.push_back(mi);

            }
            else{
                invalid = true;
                break;
            }
        }

        if(invalid){
            int ih = stoi(hh);
            int im = stoi(mm);
            
        }
        else{
            int nh = stoi(mh);
            int nm = stoi(mmm);

            if(nh < h && nm < m){
                cout << hh << ":" << mm << endl;
            }
            else{
                cout << "00:00" << endl;
            }
        }

    }
    return 0;
}