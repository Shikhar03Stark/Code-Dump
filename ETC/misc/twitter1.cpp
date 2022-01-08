#include <bits/stdc++.h>
using namespace std;

int finalInstances(int instances, vector<int> averageUtil){
    int m_int = 2*1e8;
    int n = averageUtil.size();
    for(int i = 0; i<n; i++){
        if(averageUtil[i] > 60){
            int to_init = 2*instances;
            if(to_init <= m_int){
                instances *= 2;
                i += 10;
            }
        }
        else if(averageUtil[i] < 25){
            if(instances > 1){
                instances = ceil((0.0+instances)/2);
                i += 10;
            }
        }
    }

    return instances;
}