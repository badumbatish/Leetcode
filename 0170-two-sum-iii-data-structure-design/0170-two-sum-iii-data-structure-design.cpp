class TwoSum {
    // store numbers and the times of appearance.
    unordered_map<int, int> nums;

public:
    // Initialize your data structure here.
    TwoSum() {}

    // Add the number to an internal data structure..
    void add(int number) { nums[number]++; }

    // Find if there exists any pair of numbers which sum is equal to the value.
    bool find(int value) {
        for (auto i : nums) {
            long complement = long(value) - long(i.first);
            if ((complement != i.first && nums.count(complement)) ||
                (complement == i.first && i.second > 1))
                return true;
        }
        return false;
    }
};