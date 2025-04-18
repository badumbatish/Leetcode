class Solution:
    def countPairs(self, nums: List[int], k: int) -> int:
        count = 0
        for i, val_i in enumerate(nums[:-1]):
            for j, val_j in enumerate(nums[i+1:], i+1):
                count += (((i * j) % k == 0) and val_i == val_j)

        return count