#include <bits/stdtr1c++.h>

typedef unsigned int ui;

using namespace std;

ui maxTokens(vector<ui> &cups){
    ui minIndex = 0;
    for(int i = 0; i<cups.size(); i++){
        if(cups[minIndex] > cups[i]){
            minIndex = i;
        }
    }

    ui tokens = 0;
    tokens += cups.size()*cups[minIndex];

    for(auto &e: cups){
        e = e - cups[minIndex];
    }

    int zero = minIndex;
    while(cups[0] != 0){
        //find next zero
        for(int i = 0; i<zero; i++){
            if(cups[i] == 0){
                zero = i;
                break;
            }
        }

        //find min in 0, zero-1
        ui min = 0;
        for(int i = 0; i<zero;i++){
            if(cups[min] > cups[i]){
                min = i;
            }
        }

        tokens += (zero)*cups[min];

        for(int i = 0; i<zero; i++){
            cups[i] -= cups[min];
        }
    }

    return tokens;


}

int main(){
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        vector<ui> cups(n);
        for(auto &token : cups){
            cin >> token;
        }

        cout << maxTokens(cups) << endl;
    }
    return 0;
}