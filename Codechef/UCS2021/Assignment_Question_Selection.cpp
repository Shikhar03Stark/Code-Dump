#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

struct Ques{
    int qno;
    int marks;
    int subparts;
};

int main(){
    int maxM, studs, q;
    cin >> maxM >> studs >> q;
    vector<int> sess(studs);
    for(int i = 0; i<studs; i++){
        cin >> sess[i];
    }
    vector<Ques> ques;
    for(int i = 1; i<=q; i++){
        Ques q;
        cin >> q.marks >> q.subparts;
        q.qno = i;
        ques.push_back(q);
    }

    auto comp = [](Ques& a, Ques& b)->bool{
        return a.subparts == b.subparts?((0.0+a.marks)/a.subparts < (0.0+b.marks)/b.subparts):a.subparts>b.subparts;
    };
    sort(begin(ques), end(ques), comp);
    /*for(auto& q: ques){
        cout << q.qno << " " << q.subparts << " " << q.marks << endl;
    }*/

    for(int i = 0; i<studs; i++){
        int tot = sess[i];
        vector<int> order;
        for(int i = 0; i<q; i++){
            if(tot >= maxM){
                break;
            }
            tot += ques[i].marks;
            order.push_back(ques[i].qno);
        }
        cout << order.size() << " ";
        sort(begin(order), end(order));
        for(auto& e : order){
            cout << e << " ";
        }
        cout << endl;
    }


    return 0;
}