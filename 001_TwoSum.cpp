#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/two-sum/

vector<int> twoSum(vector<int>& nums, int target) 
{
    map<int, int> itemIdxMap;
    vector<int> res;

    for(int i = 0; i < nums.size(); i++) {
        int comp = target - nums.at(i);
        if(itemIdxMap.count(comp)) {
            res.push_back(itemIdxMap[comp]);
            res.push_back(i);
        } else {
            itemIdxMap[nums.at(i)] = i;
        }
    }
    
    return res;
}

int main(){
    
    vector<int> nums {3,6,7,8};
    int target = 9;
    auto res = twoSum(nums, target);
    
    for(const auto &it : res) {
        cout << it << ", ";
    }
    cout << "\n";
}