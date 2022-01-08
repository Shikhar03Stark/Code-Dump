#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;



struct Street {
    string name;
    int start, end;
    int length;
    queue<int> wait;
    set<int> timepoint;
    
    bool operator==(string name){
        return this->name == name;
    }

    int interval=1;

};

int hcf(Street& st){
    vector<int> nums;
    for(auto& e : st.timepoint){
        nums.push_back(e);
    }
    int max = 1;
    for(int i = 0; i<nums.size(); i++){
        int count = 1;
        for(int j = i+1; j<nums.size(); j++){
            if(nums[j] % nums[i] == 0){
                count++;
            }
        }
        max = std::max(max, count);
    }

    return max;
}

int main(){
    int D, I, S, V, F;
    cin >> D >> I >> S >> V >> F;
    //I nodes
    //Streets are simple directed edge using adj list
    //edge list
    vector<vector<pair<int,int>>> list(S);
    //for output mapping
    map<pair<int,int>, string> streetName;
    map<string, pair<pair<int, int>, int>> strToEdge;
    //inbound
    vector<vector<int>> inBound(S);
    //vector of street
    vector<Street> street(S);
    for(int i = 0; i<S; i++){
        string name;
        int u, v, l;
        cin >> u >> v >> name >> l;

        //directed
        list[u].push_back({v, l});
        streetName[{u,v}] = name;
        //inbound
        inBound[v].push_back(u);
        //  
        street[i].start = u; street[i].end = v;
        street[i].length = l;
        street[i].wait = queue<int>();
        street[i].name = name;

        strToEdge[name] = {{u,v}, l};

    }

    //each vehicle is vector of strings
    vector<vector<string>> vehicle(V);
    for(int i = 0; i<V; i++){
        int streets;
        cin >> streets;
        for(int j = 0; j<streets; j++){
            string str;
            cin >> str;
            vehicle[i].push_back(str);
        }
    }

    auto comp = [&](vector<string> &a, vector<string> &b){
        int la=0, lb=0;
        for(auto s: a){
            auto edge = strToEdge[s];
            la += edge.second;
        }

        for(auto s: b){
            auto edge = strToEdge[s];
            lb += edge.second;
        }

        return la <= lb;
    };
    sort(vehicle.begin(), vehicle.end(), comp);

    for(int i = 0; i<V; i++){
        string ed = vehicle[i][0];
        int index = find(street.begin(), street.end(), ed) - street.begin();
        street[index].wait.push(i);
    }
    //1st Approach
    vector<int> nodes;
    for(int v = 0; v<vehicle.size(); v++){
        auto veh = vehicle[v];
        int index = (find(street.begin(), street.end(), veh[0])) - street.begin();
        street[index].timepoint.insert(1);
        int tot = 0;
        for(int i = 1; i<veh.size(); i++){
            string stre = veh[i];
            int index = (find(street.begin(), street.end(), stre)) - street.begin();
            tot += street[index].length;
            street[index].timepoint.insert(tot);
        }
    }

    for(auto & edge : street){
        int h = hcf(edge);
        auto index = find(street.begin(), street.end(), streetName[{edge.start, edge.end}]) - street.begin();
        street[index].interval = h;
    }



    //queue will contain index of vehicle waiting at waitQ[i] street;
    /*for(int t = 0; t<=D; t++){
        Street mCon;
        for(int k = 0; k<inBound.size(); k++){
            auto i = inBound[k];
            int num = i.size();
            int ma = 0;
            for(int j = 0; j<num; j++){
                auto st = *(find(street.begin(), street.end(), streetName[{inBound[k][j], k}] ));

            }
        }
    }*/


    nodes.resize(I);
    cout << nodes.size() << endl;
    for(int i = 0; i<nodes.size(); i++){
        cout << i << endl;
        cout << inBound[i].size() << endl;
        int ma = inBound[i].size();

        for(auto& start: inBound[i]){
            int rnd = 1 + rand() % ma;
            
            cout << streetName[{start,i}] << " " << (*(find(street.begin(), street.end(), streetName[{start,i}]))).interval << endl;
        }
    }
    

    return 0;
}