#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {

    // int total_sum = 0;
    // int total_num = 0;

    // total_sum = (nums.size() * (nums.size() + 1)) / 2;
    // for(auto &it : nums) {
    //     total_num = total_num + it;
    // }
    // return (total_sum - total_num);

    // int sum = nums.size();
    // for (int i = 0; i < nums.size(); i++) {
    //     sum += i - nums[i];
    // }
    // return sum;

    int sum = nums.size();
    for(int i = 0; i < nums.size(); i++) {
        sum ^= i ^ nums[i];
    }
    return sum;
}


int main () {
    vector<int> v{3, 0, 1};
    cout << missingNumber(v) << endl;
    return 0;
}