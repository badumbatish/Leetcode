#include <vector>
#include <cmath>

class NumArray {
private:
    std::vector<int> nums;  // Original array
    std::vector<int> blocks; // Sum of each block
    int blockSize;          // Size of each block

public:
    NumArray(std::vector<int>& nums) {
        this->nums = nums;
        int n = nums.size();
        blockSize = static_cast<int>(std::sqrt(n)) + 1; // Determine block size
        blocks.resize(blockSize, 0);

        // Preprocess: Compute the sum of each block
        for (int i = 0; i < n; ++i) {
            blocks[i / blockSize] += nums[i];
        }
    }

    void update(int index, int val) {
        int blockIndex = index / blockSize;
        blocks[blockIndex] += val - nums[index]; // Update the block sum
        nums[index] = val; // Update the original array
    }

    int sumRange(int left, int right) {
        int sum = 0;
        int startBlock = left / blockSize;
        int endBlock = right / blockSize;

        if (startBlock == endBlock) {
            // If the range is within a single block
            for (int i = left; i <= right; ++i) {
                sum += nums[i];
            }
        } else {
            // Add elements from the partially covered left block
            for (int i = left; i < (startBlock + 1) * blockSize; ++i) {
                sum += nums[i];
            }
            // Add elements from the fully covered blocks
            for (int i = startBlock + 1; i < endBlock; ++i) {
                sum += blocks[i];
            }
            // Add elements from the partially covered right block
            for (int i = endBlock * blockSize; i <= right; ++i) {
                sum += nums[i];
            }
        }
        return sum;
    }
};