#include <iostream>
#include <vector>

using namespace std;

typedef long int li;
typedef long unsigned int lui;

vector<int> optNum(int x){
    vector<int> digits;

    while(x > 0){
        x -= 9;
        digits.push_back(9);
    }


    return digits;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        lui a, b;
        cin >> a >> b;

        auto d_a = optNum(a);
        auto d_b =  optNum(b);

        if(d_a.size() == d_b.size()){
            cout << 1 << " " << d_a.size() << endl;
        }
        else{
            if(d_a.size() > d_b.size()){
                cout << 0 << " " << d_a.size() << endl;
            }
            else{
                cout << 1 << " " << d_b.size() << endl;
            }
        }

    }
    return 0;
}