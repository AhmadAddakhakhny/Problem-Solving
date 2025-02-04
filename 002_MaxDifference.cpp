    int maximumDifference(vector<int>& nums) {
        int max = -1;
        for (int i =0; i < nums.size()-1; i++) {
            for (int j =nums.size() -1; j > i; j--) {
                if (nums[j] > nums[i]) {
                    max = std::max(max, (nums[j] - nums[i]));
                }
            }
        }
        // [87,68,91,86,58,63,43,98,6,40]
        // int max = -1;
        // for(int i = 0, j = nums.size() -1 ; i <= j;) {
        //     if (nums[j] > nums[i]) {
        //         max = std::max(max, (nums[j] - nums[i]));
        //         j--;
        //     } else {
        //         i++;
        //     }
        // }

        return max;
    }
