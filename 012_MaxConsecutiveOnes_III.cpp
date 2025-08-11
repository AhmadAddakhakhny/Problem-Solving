#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& nums, int k) {

    int l = 0, r = 0, max = 0, maxFlip = 0;

    for (;r < nums.size(); r++) {
        if (nums[r] == 0) {
            maxFlip++;
            while (maxFlip > k) {
                maxFlip -= (nums[l++] == 0);
            }
        }
        
        max = std::max(max, (r - l + 1));
    }
    
    return max;
}

int main () {

    vector<int> nums{0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k = 3; // Output: 10
    // vector<int> nums{1,1,1,0,0,0,1,1,1,1,0};
    // int k = 2;   // Output: 6   
    cout << longestOnes(nums,k) << std::endl;
    return 0;
}