class Solution {
public:
    int singleNumber(vector<int>& nums) {
    //         If we take XOR of zero and some bit, it will return that bit
    // a⊕0 = a
    // If we take XOR of two same bits, it will return 0
    // a⊕a = 0
    // a⊕b⊕a =(a⊕a)⊕b = 0⊕b = b
    // So we can XOR all bits together to find the unique number.
        return std::reduce(nums.begin(), nums.end(), 0, std::bit_xor<int>());
    }
};