class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int max = 0, current_sum = 0; 

        int left =0, right = 0;

        int sz = nums.size();
        while (left < sz && right < sz) {
            if (nums[right] == 0) {
                    // Shrink until meet another zero
                while (k == 0) {
                    if (nums[left] == 0) k = k + 1;
                    current_sum = current_sum - 1;
                    left++;
                }
                k--;
            } 
            current_sum += 1;
            max= std::max(current_sum, max);
            right += 1;
        }

        return max;
    }
    // max is 3 now (updated every left move or right move)
    // can have 2 zeroes with whatever ones next to it (consecutively)

    // current_max = 0
    // [0, 1, 0, 0] k = 2
    //  l.       
    //. r
    
    // current_max = 1
    // [0, 1, 0, 0] k = 1 (I have 2 flips to use before, i have flipped at right =0, so now k = 1) 
    //  l.       
    //.    r
    // 

    // current_max = 2
    // [0, 1, 0, 0] k = 0 (I have 2 flips to use before, i have flipped at right =0, so now k = 1) 
    //  l.       
    //.       r
    // 

    // current_max = 3
    // [0, 1, 0, 0] k = 1 (I have 2 flips to use before, i have flipped at right =0, so now k = 1) 
    //     l.       
    //.          r
    // 
};