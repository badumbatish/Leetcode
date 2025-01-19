class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        //I've just failed a pliminary Facebook interview with this question.
        //After some retrospec about my thought process, here is the intiution that might have worked for me:
        //
        //We want to find a larger number, but not too large - just the next larger one =>
        //We want to avoid chaning the number in the left - it will increase the number too much =>
        //Example: 4325413 -> we can only change the last two numbers and have 432531
        //What if it was 432531 in the first place? 31 cannot be increased.
        //Lets try 531 - still no
        //2531 - this can be incrased - the smallest number that can be used to incrase the 2 is 3. so for now we have 3521.
        //Next we want to minimize 3521 - thats easier - just sort the numbers to the right of 3 - 3125. So the unswer is 4323125

        int next_to_decrease = nums.size() - 2;
        while (next_to_decrease >= 0 && nums[next_to_decrease] >= nums[next_to_decrease + 1])
            next_to_decrease--;

        if (next_to_decrease == -1) {
            std::ranges::sort(nums);
            return;
        } 

        int larger_than = nums.size() - 1;
        while (nums[larger_than] <= nums[next_to_decrease]) larger_than--;
        std::swap(nums[larger_than], nums[next_to_decrease]);
        std::sort(nums.begin() + next_to_decrease + 1, nums.end());
    }
};