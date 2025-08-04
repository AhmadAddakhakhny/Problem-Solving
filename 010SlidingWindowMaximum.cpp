#include <iostream>
#include<bits/stdc++.h>

using namespace std;


// https://leetcode.com/problems/sliding-window-maximum/description/
struct Compare {
    bool operator()(const pair<int, vector<int>>& a, const pair<int, vector<int>>& b) {
        return a.first < b.first;
    }
};

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int total_sum = 0;
    int max_val = INT_MIN;
    vector<int> max_elements;
    
    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, Compare> pq_cache;

    for (int start = 0; start < k; start++) {
        total_sum += nums[start];
        
        max_elements.push_back(nums[start]);
    }

    pq_cache.emplace(total_sum, max_elements);

    for (int start = k; start < nums.size(); start++) {
        total_sum += (nums[start] - nums[start - k]); 

        max_elements.erase(max_elements.begin()); 
        max_elements.push_back(nums[start]);
        pq_cache.emplace(total_sum, max_elements);
    }

    // Get the top element (maximum sum and window)
    pair<int, vector<int>> keyVal = pq_cache.top();
    pq_cache.pop(); // Pop the top element from the priority queue

    vector<int> res = keyVal.second; // Extract the window from the pair
    return res;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = maxSlidingWindow(nums, k);

    // Output the result
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}
