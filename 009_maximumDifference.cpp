int maximumDifference(vector<int>& nums) {
    int max_val = -1;
    int max_idx = nums.back();

    for(int i = nums.size()-2; i >=0; i--) {
        if(nums.at(i)<max_idx) {
            max_val = std::max(max_val, (max_idx - nums.at(i)));
        }
        max_idx = std::max(max_idx, nums.at(i));
    }
    return max_val;
}

int main () {
    vector<int> v{87,68,91,86,58,63,43,98,6,40}; // 55 !34
    cout << maximumDifference(v) << std::endl;
    return 0;
}
