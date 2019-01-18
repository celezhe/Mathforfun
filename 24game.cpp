//
//  main.cpp
//  4_10s
//
//  Created by air on 19/1/18.
//  Copyright © 2019年 Ruizhe Huang. All rights reserved.
//


#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
void helper(vector<double> res, set<double> &result, string s) {
    if (res.size() == 1) {
        if (res[0] == floor(res[0])) {
            result.insert(res[0]);
        }
        return;
    }
    if (res.size() == 2) {
        if (res[0] + res[1] == floor(res[0] + res[1])) {
            result.insert(res[0] + res[1]);
        }
        if (res[0] * res[1] == floor(res[0] * res[1])) {
            result.insert(res[0] * res[1]);
        }
        if ((res[0] - res[1]) == floor(res[0] - res[1])) {
            result.insert(res[0] - res[1]);
            result.insert(-res[0] + res[1]);
        }
        if (((res[0]*1.0) / res[1]) == floor((res[0]*1.0) / res[1])) {
            result.insert(res[0] / res[1]);
        }
        if (((res[1]*1.0) / res[0]) == floor((res[1]*1.0) / res[0])) {
            result.insert(res[1] / res[0]);
        }
        return;
    }
    for (int i = 0; i < res.size(); i++ ){
        for (int j = i + 1; j < res.size(); j++) {
            double current1 = res[i];
            double current2 = res[j];
            vector<double> temp = res;
            res.erase(find(res.begin(), res.end(), current1));
            res.erase(find(res.begin(), res.end(), current2));
            res.push_back(current1 + current2);
            helper(res, result, s+"+");
            res.pop_back();
            res.push_back(current1 * current2);
            helper(res, result, s+"*");
            res.pop_back();
            res.push_back(current1 - current2);
            helper(res, result, s+"-");
            res.pop_back();
            res.push_back(current2 - current1);
            helper(res, result, s+"-");
            res.pop_back();
            res.push_back((current1*1.0) / current2);
            helper(res, result, s+"/");
            res.pop_back();
            res.push_back((current2*1.0) / current1);
            helper(res, result, s+"/");
            res.pop_back();
            res = temp;
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    set<double> s;
    vector<double> vec={10,10,10, 10};
    string k="";
    helper(vec, s, k);

    for (auto x:s) {
        cout << x << endl;
    }
    return 0;
}

