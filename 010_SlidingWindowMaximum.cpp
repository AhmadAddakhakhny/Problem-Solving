#include <iostream>
#include<bits/stdc++.h>

using namespace std;


vector<int> maxSlidingWindow(vector<int>& nums, int k) {

    map<int, int> mp_max_frq;
    vector<int> max_res;
    auto it = mp_max_frq.begin();
    int max;

    for (int start = 0; start < k; start++) {
        mp_max_frq[nums[start]]++;
    }

    it = mp_max_frq.end();
    it--;
    max = (*(it)).first;
    max_res.push_back(max);

    for (int start = k; start < nums.size(); start++) {

        // remove leading element
        if (mp_max_frq[nums[start-k]] == 1) {
            mp_max_frq.erase(nums[start-k]);
        } else {
            mp_max_frq[nums[start-k]]--;
        }
        
        // Add new element
        mp_max_frq[nums[start]]++;

        // get max
        it = mp_max_frq.end();
        it--;
        max = (*(it)).first;
        max_res.push_back(max);
    }

    return max_res;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    // vector<int>nums = {1,-1};
    // int k = 1;

    vector<int> result = maxSlidingWindow(nums, k);

    // Output the result
    // for (int num : result) {
    //     cout << num << " ";
    // }
    
    return 0;
}
