class NumArray {
    int block_size;
    std::vector<int>& nums;
    std::vector<int> blocks;
public:
    NumArray(vector<int>& nums) : nums(nums) {
        double l = sqrt(nums.size());

        block_size = ceil(nums.size() / l);

        blocks = std::vector<int>(block_size, 0);
        
        // Set up blocks
        for (int i = 0; i < nums.size(); i++) blocks[i / block_size] += nums[i];

    }
    
    void update(int index, int val) {
        int block_index = index / block_size;
        blocks[block_index] = blocks[block_index] - nums[index] + val;
        nums[index] = val;

    }
    
    int sumRange(int left, int right) {
        int start_block = left / block_size;
        int end_block = right / block_size;

        if (start_block == end_block) {
            return std::accumulate(nums.begin() + left, nums.begin() + right + 1, 0);
        }

        int sum = 0;

        //
        for (int k = left; k < (start_block + 1) * block_size ; k++) sum += nums[k];
        for (int k = start_block + 1; k <= end_block - 1; k++) sum += blocks[k];
        for (int k = end_block * block_size; k <= right; k++) sum += nums[k];

        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */