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

// vector<int> usingQueue(vector<int> &nums, int &k) {

//     deque<int> dq;
//     // store max index of window
//     vector<int> ans;

//     // process first window
//     for (int i = 0; i<k; i++) {
//         // remove small element on left side - direction of curr to q.front() (right to left)
//         while (!dq.empty() && nums[dq.back()] < nums[i]) {
//             // cant remove 1 in window [3,1,2] by use of q.pop()
//             // thats why we remove from back
//             dq.pop_back();
//         }
//         // insert curr element
//         dq.push_back(i);
//     }
//     // ans for first ans
//     ans.push_back(nums[dq.front()]);

//     // remaining windows
//     for (int i = k; i<nums.size(); i++) {
//         // remove out of range from front
//         while (!dq.empty() && dq.front() <= i-k) {
//             dq.pop_front();
//         }
//         // remove small element on left side - direction of curr to q.front() (right to left)
//         while (!dq.empty() && nums[dq.back()] < nums[i]) {
//             // cant remove 1 in window [3,1,2] by use of q.pop()
//             // thats why we remove from back
//             dq.pop_back();
//         }
//         // insert curr element
//         dq.push_back(i);
//         // ans store
//         ans.push_back(nums[dq.front()]);
//     }

//     return ans;
// }

// vector<int> usingMaxHeap(vector<int> &nums, int k) {

//     vector<int> ans;

//     priority_queue<pair<int, int>> maxHeap; // element, idx

//     // init. - first window
//     for (int i = 0; i < nums.size() && i < k; i++) {
//         maxHeap.push({nums[i], i});
//     }
//     // store max of first window
//     ans.push_back(maxHeap.top().first);

//     // process for remaining window
//     for (int i = k; i < nums.size(); i++) {

//         // remvoe old window maxx
//         while (!maxHeap.empty() && maxHeap.top().second <= i - k) {
//             maxHeap.pop();
//         }

//         // insert new element
//         maxHeap.push({nums[i], i});

//         // store in ans
//         ans.push_back(maxHeap.top().first);
//     }

//     return ans;
// }


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
