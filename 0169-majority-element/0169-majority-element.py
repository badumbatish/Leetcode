class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        current_candidate = nums[0]
        current_count = 1

        for i in range(1, len(nums)):
            if current_candidate is None:
                current_candidate = nums[i]
                current_count += 1
                continue

            if current_candidate == nums[i]:
                current_count += 1
            else:
                current_count -= 1

            if current_count == 0:
                current_candidate = None

        
        return current_candidate