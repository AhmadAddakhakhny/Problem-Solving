#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// LeetCode 219 - Contains Duplicate II
// Adjust the below window technique, and also solve it using  map of <value, index> 

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    map<int, bool> mp;
    bool status = false;
    k++;

    for (int i = 0; i < k && !status && i < nums.size(); i++) {
        status = mp.count(nums[i]);
        if (!status) {
            mp[nums[i]] = true;
        }        
    }

    if(!status) {
        for (int start = k; start < nums.size() && !status && start < nums.size(); start ++) {
            // remove first emlement
            mp.erase(nums[start-k]);
            // check if the element to be inserted existed
            status = mp.count(nums[start]);
            // add new element
            if (!status) {
                mp[nums[start]] = true;
            }       
        }
    }

    return status;
}
int main () {

    // vector<int> nums{1,2,3,1};
    // int k = 3; // Output: true
    // vector<int> nums{1,0,1,1};
    // int k = 1;   // Output: true   
    // vector<int> nums{1,2,3,1,2,3};
    // int k = 2;   // Output: false   
    vector<int> nums{1,2,3,4,5,6,7,8,9,9};
    int k = 3;   // Output: false 

    cout << containsNearbyDuplicate(nums,k) << std::endl;
    return 0;
}