#include<iostream>
#include<bits/stdc++.h>
using namespace std;


vector<int> maxSlidingWindow(vector<int>& nums, int k) {
vector<int> ans;
        deque<int> q;

        for (int i = 0; i < k; i++) {
            while(!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }

        ans.push_back(nums[q.front()]);

        for (int i = k; i < nums.size(); i++) {
            // removal
            if (!q.empty() && i - q.front() >= k) {
                q.pop_front();
            }
            // insertion
            while(!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }
            q.push_back(i);

            // store
            ans.push_back(nums[q.front()]);
        }
        return ans;
}

int main(){
  vector<int> v{1,3,1,2,0,5};
  int k = 3;

  vector<int> mm = maxSlidingWindow(v, k);

  for(auto m : mm )
    cout << m << " ";
  cout << "\n";
  return 0;
}
